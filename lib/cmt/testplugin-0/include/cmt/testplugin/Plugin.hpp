#ifndef CMT_TESTPLUGIN_PLUGIN_HPP
#define CMT_TESTPLUGIN_PLUGIN_HPP

#include "internal/platform.hpp"

#include <cmt/Plugin.hpp>

namespace cmt {
namespace testplugin {

class CMT_TESTPLUGIN_API Plugin:
	public cmt::Plugin<Plugin>
{
	public:
		Plugin();

		~Plugin() override;

		void configure(const toml::table & config) override;
};

}
}

CMT_DEFINE_PLUGIN(cmt::testplugin::Plugin)

#endif
