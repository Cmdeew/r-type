#ifndef _CWABSMUTEX_H_
# define _CWABSMUTEX_H_

#ifdef _WIN32
#include <windows.h>
#include "AbsMutex.h"

class	CWAbsMutex : public AbsMutex
{
 public:
 bool	AMutexInit(thread_mutex mutext);
  bool	AMutexLock(thread_mutex mutext);
  bool	AMutexTryLock(thread_mutex mutext);
  bool	AMutexUnLock(thread_mutex mutext);
  bool	AMutexDestroy(thread_mutex mutext);
  CWAbsMutex();
  ~CWAbsMutex();
};
#endif

#endif //_CWABSMUTEX_H_
