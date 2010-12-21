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
  bool	AMutexInit(thread_mutex mutext);
  bool	AMutexDestroy(thread_mutex mutext);
  bool	AMutexLock(thread_mutex mutext);
  bool	AMutexTryLock(thread_mutex mutext);
  bool	AMutexUnLock(thread_mutex mutext);
  void	ASleep(unsigned int seconds);
  CWAbsThread();
  ~CWAbsThread();
};
#endif

#endif //_CWABSTHREAD_H_
