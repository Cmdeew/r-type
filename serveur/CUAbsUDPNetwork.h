#ifndef _CUABSUDPNETWORK
#define _CUABSUDPNETWORK

#include "AbsUDPNetwork.h"
#define	ERROR_SOCKET "Error in Socket"

class	CUAbsUDPNetwork : public AbsUDPNetwork
{
public:
  CUAbsUDPNetwork();
  ~CUAbsUDPNetwork();
  Socket CreateSocket();
  int   Receive(void *Buffer);
  int   Send(const void *Buffer, size_t size);
  int   CloseSocket();
  void	Bind(void);
  void	setArg(char **);
};

#endif
