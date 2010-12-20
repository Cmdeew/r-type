#ifndef _ABSTHREAD_H_
# define _ABSTHREAD_H_

#include "IAbsThread.h"

class	AbsThread : public IAbsThread
{
  private:
  hand				Handle;
  thread_mutex		mutex;
 public:
  AbsThread();
  ~AbsThread();
  hand			getHandle() const;
  void			setHandle(hand Hand);
  thread_mutex	getMutex() const;
  void			setMutex(thread_mutex M);
};


#endif //_ABSTHREAD_H_
