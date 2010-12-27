#ifdef _WIN32

#include <windows.h>
#include "CWAbsMutex.h"

CWAbsMutex::CWAbsMutex()
{
}

CWAbsMutex::~CWAbsMutex()
{
}

bool	CWAbsMutex::AMutexInit(thread_mutex mutext)
{
  InitializeCriticalSection((LPCRITICAL_SECTION)mutext);
  return (true);
}

bool	CWAbsMutex::AMutexDestroy(thread_mutex mutext)
{
 DeleteCriticalSection((LPCRITICAL_SECTION)mutext);
 return(true);
}

bool	CWAbsMutex::AMutexLock(thread_mutex mutext)
{
  EnterCriticalSection((LPCRITICAL_SECTION)mutext);
  return (true);
}

bool	CWAbsMutex::AMutexTryLock(thread_mutex mutext)
{
  if (TryEnterCriticalSection((LPCRITICAL_SECTION)mutext) == TRUE)
	return (true);
  return (false);
}

bool	CWAbsMutex::AMutexUnLock(thread_mutex mutext)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)mutext);
  return (true);
}

#endif
