#ifndef _CUABSMUTEX_H_
# define _CUABSMUTEX_H_

#ifndef _WIN32
#include "AbsMutex.h"

class	CUAbsMutex : public AbsMutex
{
 public:
  bool	AMutexInit(thread_mutex mutext);
  bool	AMutexDestroy(thread_mutex mutext);
  bool	AMutexLock(thread_mutex mutext);
  bool	AMutexTryLock(thread_mutex mutext);
  bool	AMutexUnLock(thread_mutex mutext);
  CUAbsMutex();
  ~CUAbsMutex();
};
#endif

#endif //_CUABSMUTEX_H_
