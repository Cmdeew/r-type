#ifndef _ABSMUTEX_H_
# define _ABSMUTEX_H_

#include "IAbsMutex.h"

class	AbsMutex : public IAbsMutex
{
  private:
  thread_mutex		mutex;
 public:
  AbsMutex();
  ~AbsMutex();
  thread_mutex		getMutex() const;
  void			setMutex(thread_mutex M);
};


#endif //_ABSMUTEX_H_
