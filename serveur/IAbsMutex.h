#ifndef _IABSMUTEX_H_
# define _IABSMUTEX_H_

#include <iostream>

typedef void *	thread_mutex;

class	IAbsMutex
{
public:
  virtual bool	AMutexInit(thread_mutex mutext) = 0;
  virtual bool	AMutexDestroy(thread_mutex mutext) = 0;
  virtual bool	AMutexLock(thread_mutex mutext) = 0;
  virtual bool	AMutexTryLock(thread_mutex mutext) = 0;
  virtual bool	AMutexUnLock(thread_mutex mutext) = 0;
};

#endif //_IABSMUTEX_H_
