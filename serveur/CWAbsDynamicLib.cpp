#ifdef _WIN32

#include "CWAbsDynamicLib.h"

CUAbsDynamicLib::CWAbsDynamicLib()
{
}

CUAbsDynamicLib::~CWAbsDynamicLib()
{
}

hand	CWAbsDynamicLib::AOpenLib(pstr name)
{
  return (NULL);
}

bool	CWAbsDynamicLib::ACloseLib(hand lib)
{
  return (true);
}

addr	CWAbsDynamicLib::ASymLib(hand lib, const char* symbol)
{
  return (NULL);
}

#endif
