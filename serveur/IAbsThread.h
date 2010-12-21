#ifndef _IABSTHREAD_H_
# define _IABSTHREAD_H_

#include <iostream>

typedef void *	hand;
typedef void *	thread;
typedef void *	thread_attr;
typedef void *	typefunc;
typedef void *	typeparam;
typedef void *	thread_mutex;

class	IAbsThread
{
public:
  virtual hand	ACreateThread(thread Thread, thread_attr ThreadAttr,
			     typefunc StartRoutine, typeparam Param) = 0;
  virtual bool	AExitThread(thread_attr ThreadAttr) = 0;
  virtual bool	AMutexInit(thread_mutex mutext) = 0;
  virtual bool	AMutexDestroy(thread_mutex mutext) = 0;
  virtual bool	AMutexLock(thread_mutex mutext) = 0;
  virtual bool	AMutexTryLock(thread_mutex mutext) = 0;
  virtual bool	AMutexUnLock(thread_mutex mutext) = 0;
  virtual void	ASleep(unsigned int seconds) = 0;
};

#endif //_IABSTHREAD_H_
