#ifdef _WIN32

#include <windows.h>
#include "CWAbsThread.h"

CWAbsThread::CWAbsThread()
{
}

CWAbsThread::~CWAbsThread()
{
}

hand	CWAbsThread::ACreateThread(thread Thread,
				  thread_attr ThreadAttr,
				  typefunc StartRoutine,
				  typeparam Param)
{
  hand	thread;

  thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) StartRoutine, (LPVOID) Param, 0, (LPDWORD) Thread);
  return (thread);
}

bool	CWAbsThread::AExitThread(thread_attr ThreadAttr)
{
  if (TerminateThread((HANDLE) ThreadAttr, 0))
	  return (true);
  return (false);
}

bool	CWAbsThread::AMutexInit(thread_mutex mutext)
{
  InitializeCriticalSection((LPCRITICAL_SECTION)mutext);
  return (true);
}

bool	CWAbsThread::AMutexDestroy(thread_mutex mutext)
{
 DeleteCriticalSection((LPCRITICAL_SECTION)mutext);
 return(true);
}

bool	CWAbsThread::AMutexLock(thread_mutex mutext)
{
  EnterCriticalSection((LPCRITICAL_SECTION)mutext);
  return (true);
}

bool	CWAbsThread::AMutexTryLock(thread_mutex mutext)
{
  if (TryEnterCriticalSection((LPCRITICAL_SECTION)mutext) == TRUE)
	return (true);
  return (false);
}

bool	CWAbsThread::AMutexUnLock(thread_mutex mutext)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)mutext);
  return (true);
}

void	CWAbsThread::ASleep(unsigned int seconds)
{
	Sleep(seconds);
}
#endif
