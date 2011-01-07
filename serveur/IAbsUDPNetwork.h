#ifndef _IAbsUDPNetwork
#define _IAbsUDPNetwork

#include <sys/types.h>
#ifndef _WIN32
#include <sys/socket.h>
#endif

typedef void * Socket;

class	IAbsUDPNetwork
{
 public:
  virtual Socket CreateSocket(int port) = 0;
  virtual int	Receive(void *Buffer) = 0;
  virtual int	Send(const void *Buffer, size_t size) = 0;
  virtual int	CloseSocket() = 0;
  virtual void	Bind(void) = 0;
  virtual void	setArg(char **argv) = 0;
};

#endif
