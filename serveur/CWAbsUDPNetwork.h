#ifndef _CWAbSUDPNETWORK
#define _CWABSUDPNETWORK

#include "AbsUDPNetwork.h"

class	CWAbsUDPNetwork : public AbsUDPNetwork
{
public:
  CWAbsUDPNetwork();
  ~CWAbsUDPNetwork();
  Socket CreateSocket();
  int   Receive(void *Buffer);
  int   Send(const void *Buffer, size_t size);
  int   CloseSocket();
  void	Bind(void);
  void	setArg(char **argv);
};

#endif
