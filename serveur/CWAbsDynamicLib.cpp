#ifdef _WIN32

#include <windows.h>
#include "CWAbsDynamicLib.h"

CWAbsDynamicLib::CWAbsDynamicLib()
{
}

CWAbsDynamicLib::~CWAbsDynamicLib()
{
}

hand	CWAbsDynamicLib::AOpenLib(pstr name)
{
  return (LoadLibrary((LPCSTR)TEXT(name)));
}

bool	CWAbsDynamicLib::ACloseLib(hand lib)
{
  if (FreeLibrary((HMODULE)lib) == TRUE)
	return (true);
  return (false);
}

addr	CWAbsDynamicLib::ASymLib(hand lib, const char* symbol)
{
  return ((void *)GetProcAddress((HMODULE)lib, (LPCSTR)symbol));
}

#endif
