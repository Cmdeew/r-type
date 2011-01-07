#include "Factory.h"

Factory::Factory()
{

}

Factory::~Factory()
{

}

AbsMutex *	Factory::n_mutex()
{
  AbsMutex	*inst;
#ifndef _WIN32
  inst = new CUAbsMutex();
#else
  inst = new CWAbsMutex();
  typedef void * CRITICAL_SECTION;
#endif
  return ((AbsMutex *)inst);
}

AbsThread *	Factory::n_thread()
{
  AbsThread	*inst;
#ifndef _WIN32
  inst = new CUAbsThread();
#else
  inst = new CWAbsThread();
  typedef void * CRITICAL_SECTION;
#endif
  return ((AbsThread *)inst);
}

AbsUDPNetwork *	Factory::n_network()
{
  AbsUDPNetwork *p;
#ifndef _WIN32
  p = new CUAbsUDPNetwork();
#else
  p = new CWAbsUDPNetwork();
#endif
  return ((AbsUDPNetwork *)p);
}
