#ifndef _AbsUDPNetwork
#define	_AbsUDPNetwork

#include "IAbsUDPNetwork.h"

#define ERROR_SEND		"Error Send"
#define ERROR_RECV		"Error Receive"
#define	ERROR_INIT_SOCKET	"Error Init Socket"
#define ERROR_CREATE_SOCKET	"Error Invalid Socket"
#define ERROR_BIND		"Error Bind"
#define BIND_OK			"Bind ok"
#define SOCKET_OK		"Socket ok"
#define SETSOCK			"Error setsockopt"
#define USAGE			"Usage : serveur [-p port] [-b BroadcastIp]"
#define	PORT			"-p"
#define	BROADCAST		"-b"

class	AbsUDPNetwork : public IAbsUDPNetwork
{
public:
  AbsUDPNetwork();
  ~AbsUDPNetwork();
  //protected:
  Socket _socket;
  int _port;
  char *_broadcast;
  struct sockaddr_in *my_addr;
};

#endif
