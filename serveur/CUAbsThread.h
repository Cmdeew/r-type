#ifndef _CUABSTHREAD_H_
# define _CUABSTHREAD_H_

#ifndef _WIN32
#include "AbsThread.h"

class	CUAbsThread : public AbsThread
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
  CUAbsThread();
  ~CUAbsThread();
};
#endif

#endif //_CUABSTHREAD_H_
