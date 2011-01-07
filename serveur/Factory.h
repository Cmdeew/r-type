#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "CWAbsThread.h"
#include "CUAbsThread.h"
#include "CUAbsUDPNetwork.h"
#include "CWAbsUDPNetwork.h"
#include "CUAbsMutex.h"
#include "CWAbsMutex.h"

class	Factory
{
 public:
  Factory();
  ~Factory();
  AbsThread *     n_thread();
  AbsUDPNetwork * n_network();
  AbsMutex *	  n_mutex();
};

#endif // _FACTORY_H_
