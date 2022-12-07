#ifndef CMT_FOO_PLUGIN_HPP
#define CMT_FOO_PLUGIN_HPP

#include "internal/platform.hpp"

#include <cmt/Plugin.hpp>

namespace cmt {
namespace foo {

class CMT_FOO_API Plugin:
	public cmt::Plugin<Plugin>
{
	public:
		void configure(const toml::table & config) override;
};

}
}

CMT_DEFINE_PLUGIN(cmt::foo::Plugin)

#endif
