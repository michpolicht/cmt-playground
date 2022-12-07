#ifndef CMT_DOC_IN_CPP_PLUGIN_HPP
#define CMT_DOC_IN_CPP_PLUGIN_HPP

#include "internal/platform.hpp"

#include <cmt/Plugin.hpp>

namespace cmt::doc::in::cpp {

class CMT_DOC_IN_CPP_API Plugin:
	public cmt::Plugin<Plugin>
{
	public:
		void configure(const toml::table & config) override;
};

}

CMT_DEFINE_PLUGIN(cmt::doc::in::cpp::Plugin)

#endif
