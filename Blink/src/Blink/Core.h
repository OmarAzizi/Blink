#pragma once

#ifdef BLINK_PLATFORM_WINDOWS
#	ifdef BLINK_BUILD_DLL
#		define BLINK_API __declspec(dllexport)
#	else
#		define BLINK_API __declspec(dllimport)
#	endif
#endif

#define BIT(x) (1 << x) // will be used to create bitmask values