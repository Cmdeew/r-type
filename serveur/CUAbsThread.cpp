#ifndef _WIN32

#include <iostream>
#include <pthread.h>
#include "CUAbsThread.h"

CUAbsThread::CUAbsThread()
{
}

CUAbsThread::~CUAbsThread()
{
}

hand	CUAbsThread::ACreateThread(thread Thread,
				  thread_attr ThreadAttr,
				  typefunc StartRoutine,
				  typeparam Param)
{
  hand	thread;

  thread = (hand)pthread_create((pthread_t*) Thread,
			       (const pthread_attr_t*)ThreadAttr,
			       (void* (*)(void*))StartRoutine,
			       Param);
			       return (thread);
}

bool	CUAbsThread::AExitThread(thread_attr ThreadAttr)
{
  pthread_exit(ThreadAttr);
  return (true);
}

bool	CUAbsThread::AMutexInit(thread_mutex mutext)
{
  if (pthread_mutex_init((pthread_mutex_t *)mutext, NULL) == 0)
    return (true);
  else
    return (false);
}

bool	CUAbsThread::AMutexDestroy(thread_mutex mutext)
{
  if (pthread_mutex_destroy((pthread_mutex_t *)mutext) == 0)
    return (true);
  else
    return (false);
}

bool	CUAbsThread::AMutexLock(thread_mutex mutext)
{
  if (pthread_mutex_lock((pthread_mutex_t *)mutext) == 0)
    return (true);
  else
    return (false);
}

bool	CUAbsThread::AMutexTryLock(thread_mutex mutext)
{
  if (pthread_mutex_trylock((pthread_mutex_t *)mutext) == 0)
    return (true);
  else
    return (false);
}

bool	CUAbsThread::AMutexUnLock(thread_mutex mutext)
{
  if (pthread_mutex_unlock((pthread_mutex_t *)mutext) == 0)
    return (true);
  else
    return (false);
}

#endif
