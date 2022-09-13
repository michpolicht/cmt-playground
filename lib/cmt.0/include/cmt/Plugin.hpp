#ifndef CMT_PLUGIN_HPP
#define CMT_PLUGIN_HPP

#include "macros.hpp"

#include <boost/dll/alias.hpp>

#include <memory>

#define CMT_DEFINE_PLUGIN(PLUGIN_CLASS) BOOST_DLL_ALIAS(PLUGIN_CLASS::create, create)

namespace cmt {

class CMT_SYMBOL_VISIBLE PluginInterface
{
	public:
		virtual ~PluginInterface() = default;

		virtual void configure() = 0;
};

template <class DERIVED>
class CMT_SYMBOL_VISIBLE Plugin:
	public PluginInterface
{
	public:
		static std::shared_ptr<PluginInterface> create();
};

template <class DERIVED>
std::shared_ptr<PluginInterface> Plugin<DERIVED>::create()
{
	return std::shared_ptr<PluginInterface>(new DERIVED());
}

}

#endif // PLUGIN_HPP
