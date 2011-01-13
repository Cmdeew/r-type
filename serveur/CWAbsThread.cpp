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

void	CWAbsThread::ASleep(unsigned int seconds)
{
	Sleep(seconds * 0.001);
}

void	CWAbsThread::APause()
{
	system("pause");
}
#endif
