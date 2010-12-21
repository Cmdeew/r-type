#ifndef _WIN32

#include <dlfcn.h>
#include "CUAbsDynamicLib.h"

CUAbsDynamicLib::CUAbsDynamicLib()
{
}

CUAbsDynamicLib::~CUAbsDynamicLib()
{
}

hand	CUAbsDynamicLib::AOpenLib(pstr name)
{
  return ((void *)dlopen((const char *)name, RTLD_GLOBAL));
}

bool	CUAbsDynamicLib::ACloseLib(hand lib)
{
  if (dlclose(lib) == 0)
    return (true);
  return (false);
}

addr	CUAbsDynamicLib::ASymLib(hand lib, const char* symbol)
{
  return ((void *)dlsym(lib, symbol));
}

#endif
