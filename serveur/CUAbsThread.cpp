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

void	CUAbsThread::ASleep(unsigned long seconds)
{
	usleep(seconds);
}

void	CUAbsThread::APause()
{
	pause();
}
#endif
