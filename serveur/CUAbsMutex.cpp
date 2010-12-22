#ifndef _WIN32

#include <iostream>
#include <pthread.h>
#include "CUAbsMutex.h"

CUAbsMutex::CUAbsMutex()
{
}

CUAbsMutex::~CUAbsMutex()
{
}

bool	CUAbsMutex::AMutexInit(thread_mutex mutext)
{
  if (pthread_mutex_init((pthread_mutex_t *)mutext, NULL) == 0)
    return (true);
  else
    return (false);
}

bool	CUAbsMutex::AMutexDestroy(thread_mutex mutext)
{
  if (pthread_mutex_destroy((pthread_mutex_t *)mutext) == 0)
    return (true);
  else
    return (false);
}

bool	CUAbsMutex::AMutexLock(thread_mutex mutext)
{
  if (pthread_mutex_lock((pthread_mutex_t *)mutext) == 0)
    return (true);
  else
    return (false);
}

bool	CUAbsMutex::AMutexTryLock(thread_mutex mutext)
{
  if (pthread_mutex_trylock((pthread_mutex_t *)mutext) == 0)
    return (true);
  else
    return (false);
}

bool	CUAbsMutex::AMutexUnLock(thread_mutex mutext)
{
  if (pthread_mutex_unlock((pthread_mutex_t *)mutext) == 0)
    return (true);
  else
    return (false);
}

#endif
