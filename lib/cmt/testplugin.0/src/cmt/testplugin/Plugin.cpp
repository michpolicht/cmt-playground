#include <cmt/testplugin/Plugin.hpp>

#include <iostream>

namespace cmt {
namespace testplugin {

Plugin::Plugin()
{
}

void Plugin::configure()
{
	std::cout << "Configure cmt.testplugin.0" << std::endl;
}

}
}
