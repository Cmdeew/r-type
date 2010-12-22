#ifndef _ABSTHREAD_H_
# define _ABSTHREAD_H_

#include "IAbsThread.h"

class	AbsThread : public IAbsThread
{
 private:
  hand				Handle;
 public:
  AbsThread();
  ~AbsThread();
  hand			getHandle() const;
  void			setHandle(hand Hand);
};


#endif //_ABSTHREAD_H_
