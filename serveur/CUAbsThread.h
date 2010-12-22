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
  void	ASleep(unsigned int seconds);
  CUAbsThread();
  ~CUAbsThread();
};
#endif

#endif //_CUABSTHREAD_H_
