#pragma once

#ifdef SC_PLATFORM_WINDOWS
	#ifdef SC_BUILD_DLL
		#define SC_API __declspec(dllexport)
	#else
		#define SC_API __declspec(dllimport)
	#endif
#else
	#error Society only supports Windows!
#endif

#define BIT(x) (1 << x)