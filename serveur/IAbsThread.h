#ifndef _IABSTHREAD_H_
# define _IABSTHREAD_H_

#include <iostream>

typedef void *	hand;
typedef void *	thread;
typedef void *	thread_attr;
typedef void *	typefunc;
typedef void *	typeparam;

class	IAbsThread
{
public:
  virtual hand	ACreateThread(thread Thread, thread_attr ThreadAttr,
			     typefunc StartRoutine, typeparam Param) = 0;
  virtual bool	AExitThread(thread_attr ThreadAttr) = 0;
  virtual void	ASleep(unsigned int seconds) = 0;
  virtual void	APause() = 0;
};

#endif //_IABSTHREAD_H_
