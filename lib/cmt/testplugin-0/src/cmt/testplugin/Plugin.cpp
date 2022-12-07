#include <cmt/testplugin/Plugin.hpp>

#include <iostream>

namespace cmt {
namespace testplugin {

Plugin::Plugin()
{
	std::cout << "Ctor testplugin" << std::endl;
}

Plugin::~Plugin()
{
	std::cout << "Destroying testplugin" << std::endl;
}

void Plugin::configure(const toml::table & config)
{
	std::cout << "Configure cmt-testplugin-0" << std::endl;
}

}
}
