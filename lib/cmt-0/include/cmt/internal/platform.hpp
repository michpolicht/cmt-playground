#ifndef CMT_PLATFORM_HPP
#define CMT_PLATFORM_HPP

#include "../macros.hpp"

#if defined(CMT_LIBRARY_BUILD)
	#define CMT_API CMT_SYMBOL_EXPORT
#else
	#define CMT_API CMT_SYMBOL_IMPORT
#endif

#endif
