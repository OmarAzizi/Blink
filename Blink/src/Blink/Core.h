#pragma once

#ifdef BLINK_PLATFORM_WINDOWS
#	ifdef BLINK_BUILD_DLL
#		define BLINK_API __declspec(dllexport)
#	else
#		define BLINK_API __declspec(dllimport)
#	endif
#endif

#ifdef BLINK_ENABLE_ASSERT
#	define BLINK_ASSER(x, ...) { if(!(x)) { BLINK_ERROR("Asserion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#	define BLINK_CORE_ASSERT(x, ...) { if(!(x)) { BLINK_CORE_ERROR("Asserion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else 
#	define BLINK_ASSERT(x, ...)
#	define BLINK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) // will be used to create bitmask values