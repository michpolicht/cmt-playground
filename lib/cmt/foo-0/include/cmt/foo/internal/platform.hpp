#ifndef CMT_FOO_PLATFORM_HPP
#define CMT_FOO_PLATFORM_HPP

#include <cmt/macros.hpp>

#if defined(CMT_LIBRARY_BUILD)
#define CMT_FOO_API CMT_SYMBOL_EXPORT
#else
#define CMT_FOO_API CMT_SYMBOL_IMPORT
#endif

#endif
