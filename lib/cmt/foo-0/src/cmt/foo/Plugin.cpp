#include <cmt/foo/Plugin.hpp>

#include <cmt/testplugin/temp.hpp>

#include <iostream>

namespace cmt {
namespace foo {

void Plugin::configure(const toml::table & config)
{
	std::cout << "Configure cmt-foo-0" << std::endl;
	temp();
}

}
}
