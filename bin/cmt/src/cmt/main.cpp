#include <cstdlib>
#include <iostream>
#include <memory>

#include <boost/dll/import.hpp>
//#include <boost/function.hpp>

#include <cmt/temp.hpp>

#include <cmt/Plugin.hpp>

void loadPlugin(const char * name)
{
	boost::dll::fs::path sharedLibraryPath(".");
	sharedLibraryPath /= name;
	std::function<std::shared_ptr<cmt::PluginInterface> ()> create;

	try {
		create = boost::dll::import_alias<std::shared_ptr<cmt::PluginInterface> ()>(
						sharedLibraryPath,
						"create",
						boost::dll::load_mode::append_decorations
				);
	} catch (const std::runtime_error & e) {
		std::cout << e.what() << std::endl;
		abort();
	}

	std::shared_ptr<cmt::PluginInterface> plugin = create();
	plugin->configure();
}

int main(int argc, char * argv[])
{
	std::cout << "Hello" << std::endl;
	std::cout << temp() << std::endl;

	loadPlugin("cmt.testplugin.0");
	loadPlugin("cmt.foo.0");

	return EXIT_SUCCESS;
}
