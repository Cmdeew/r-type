#include "AbsThread.h"

AbsThread::AbsThread()
{
}

AbsThread::~AbsThread()
{
}

hand	AbsThread::getHandle() const
{
	return (Handle);
}

void	AbsThread::setHandle(hand Hand)
{
	Handle = Hand;
}

thread_mutex	AbsThread::getMutex() const
{	
	return (mutex);
}

void			AbsThread::setMutex(thread_mutex M)
{
	mutex = M;
}