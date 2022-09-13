#include <cmt/foo/Plugin.hpp>

#include <iostream>

namespace cmt {
namespace foo {

Plugin::Plugin()
{
}

void Plugin::configure()
{
	std::cout << "Configure cmt.foo.0" << std::endl;
}

}
}
