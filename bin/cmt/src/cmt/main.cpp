#include <cstdlib>
#include <iostream>
#include <memory>
#include <string_view>

#include <boost/dll/import.hpp>
//#include <boost/function.hpp>

#include <cmt/temp.hpp>

#include <cmt/Plugin.hpp>

#include <toml++/toml.h>

class PluginLoader
{
	public:
		PluginLoader(const std::string & name);

		const cmt::PluginInterface & plugin() const;

		cmt::PluginInterface & plugin();

	private:
		typedef boost::shared_ptr<cmt::PluginInterface> (PluginConstructor)();
		typedef std::function<PluginConstructor> PluginInstantiator;

		PluginInstantiator m_instantiator;
		boost::shared_ptr<cmt::PluginInterface> m_interface;
};

PluginLoader::PluginLoader(const std::string & name)
{
	boost::dll::fs::path sharedLibraryPath(".");
	sharedLibraryPath /= name;

	try {
		m_instantiator = boost::dll::import_alias<PluginConstructor>(
						sharedLibraryPath,
						"create",
						boost::dll::load_mode::append_decorations
				);
	} catch (const std::runtime_error & e) {
		std::cout << e.what() << std::endl;
		abort();
	}

	m_interface = m_instantiator();
}

const cmt::PluginInterface & PluginLoader::plugin() const
{
	return *m_interface;
}

cmt::PluginInterface & PluginLoader::plugin()
{
	return *m_interface;
}

//void loadPlugin(const std::string & name)
//{
//	boost::dll::fs::path sharedLibraryPath(".");
//	sharedLibraryPath /= name;
//	PluginInstantiator instantiator;

//	try {
//		instantiator = boost::dll::import_alias<PluginConstructor>(
//						sharedLibraryPath,
//						"create",
//						boost::dll::load_mode::append_decorations
//				);
//	} catch (const std::runtime_error & e) {
//		std::cout << e.what() << std::endl;
//		abort();
//	}

//	boost::shared_ptr<cmt::PluginInterface> plugin = instantiator();
////	return PluginKeeper(instantiator, plugin);
//}

int main(int argc, char * argv[])
{
	using namespace std::literals;

//	std::cout << "Hello" << std::endl;
//	std::cout << temp() << std::endl;
	toml::table config;
	try {
		config = toml::parse_file("C:\\Users\\michal\\Documents\\Development\\CMT Playground.master\\cmt-playground\\_toml_files\\cpp.toml");
//		std::cout << config << "\n";
	} catch (const toml::parse_error & err) {
		std::cerr << "Parsing failed:\n" << err << "\n";
		return EXIT_FAILURE;
	}

//	std::string_view library_name = config["library"]["name"].value_or(""sv);
//	std::string_view library_author = config["library"]["authors"][0].value_or(""sv);
//	int64_t depends_on_cpp_version = config["dependencies"]["cpp"].value_or(0);
//	std::cout << plugin["cmt_test_plugin.0"];

//	std::cout << library_name << " " << library_author << " " << depends_on_cpp_version << "\n";

//	config.for_each([](auto & key, auto & value)
//	{
//		std::cout << key << ": " << value << "\n";
//		if constexpr (toml::is_string<decltype(value)>)
//			do_something_with_string_values(value);
//	});

	// A vector that prevents plugins being unloaded due to PluginLoader destruction.
	std::vector<PluginLoader> pluginKeeper;

	if (config["plugin"].is_table()) {
		config["plugin"].as_table()->for_each([& pluginKeeper](auto & key, auto && value) {
			std::string pluginName;
//			std::cout << typeid(decltype(key)).name() << "\n";
//			if constexpr (toml::is_string<decltype(key)>) {
			pluginName = key.str();

//			std::cout << typeid(decltype(value)).name() << "\n";
			if constexpr (toml::is_array<decltype(value)>) {
				toml::array & paramsArray = value;
				paramsArray.for_each([& pluginName, & pluginKeeper](auto && paramsArrayElement) {
//					std::cout << "Params array element: " << paramsArrayElement << "\n";
//					std::cout << typeid(decltype(paramsArrayElement)).name() << "\n";
					PluginLoader pluginLoader(pluginName);
					pluginKeeper.push_back(pluginLoader);
					if constexpr (toml::is_table<decltype(paramsArrayElement)>)
						pluginLoader.plugin().configure(*paramsArrayElement.as_table());
				});
			} else {
//				std::cout << "Params: " << value << "\n";
//				std::cout << typeid(decltype(value)).name() << "\n";
				PluginLoader pluginLoader(pluginName);
				pluginKeeper.push_back(pluginLoader);
				if constexpr (toml::is_table<decltype(value)>)
					pluginLoader.plugin().configure(*value.as_table());
			}
		});
	}

//	loadPlugin("cmt-testplugin_0");
//	loadPlugin("cmt-foo_0");


	return EXIT_SUCCESS;
}
