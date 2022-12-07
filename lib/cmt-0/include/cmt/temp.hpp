#ifndef TEMP_H
#define TEMP_H

#include "macros.hpp"

#if defined(CMT_LIBRARY_BUILD)
	#define CMT_API CMT_SYMBOL_EXPORT
#else
	#define CMT_API CMT_SYMBOL_IMPORT
#endif

int CMT_API temp();

#endif
