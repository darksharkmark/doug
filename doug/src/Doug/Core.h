#pragma once

#ifdef DOUG_PLATFORM_WINDOWS
	#ifdef DOUG_BUILD_DLL
		#define DOUG_API __declspec(dllexport)
	#else
		#define DOUG_API __declspec(dllimport)
	#endif 
#else
	#error DOUG only runs on Windows!
#endif 

