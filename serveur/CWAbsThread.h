#ifndef _CWABSTHREAD_H_
# define _CWABSTHREAD_H_

#ifdef _WIN32
#include <windows.h>
#include "AbsThread.h"

class	CWAbsThread : public AbsThread
{
 public:
  hand  ACreateThread(thread Thread, thread_attr ThreadAttr,
		     typefunc StartRoutine, typeparam Param);
  bool	AExitThread(thread_attr ThreadAttr);
  void	ASleep(unsigned int seconds);
  CWAbsThread();
  ~CWAbsThread();
};
#endif

#endif //_CWABSTHREAD_H_
