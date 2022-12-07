#include <cmt/doc/in/cpp/Plugin.hpp>

#include <iostream>

namespace cmt::doc::in::cpp {

void Plugin::configure(const toml::table & config)
{
	std::cout << "Configure cmt-doc-in-cpp-0" << std::endl;
}

}
