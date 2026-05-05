#pragma once

#ifdef SINGLETONLIB_EXPORTS
#define SINGLETON_API __declspec(dllexport)
#else
#define SINGLETON_API __declspec(dllimport)
#endif