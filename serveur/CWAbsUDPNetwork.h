#ifndef _CWAbSUDPNETWORK
#define _CWABSUDPNETWORK

#include "AbsUDPNetwork.h"

class	CWAbsUDPNetwork : public AbsUDPNetwork
{
public:
  CWAbsUDPNetwork();
  ~CWAbsUDPNetwork();
  Socket CreateSocket(int port);
  int   Receive(void *Buffer);
  int   Send(const void *Buffer, size_t size);
  int   CloseSocket();
  void	Bind(Socket sock);
  void	setArg(char **argv);
};

#endif
