#include "AbsMutex.h"

AbsMutex::AbsMutex()
{
}

AbsMutex::~AbsMutex()
{
}

thread_mutex	AbsMutex::getMutex() const
{	
  return (mutex);
}

void		AbsMutex::setMutex(thread_mutex M)
{
  mutex = M;
}
