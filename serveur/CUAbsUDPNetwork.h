#ifndef _CUABSUDPNETWORK
#define _CUABSUDPNETWORK

#include "AbsUDPNetwork.h"
#define	ERROR_SOCKET "Error in Socket"
#define CMD_SIZE	8

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
