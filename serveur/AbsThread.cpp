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
