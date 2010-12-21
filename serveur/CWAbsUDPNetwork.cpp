#ifdef _WIN32

#include	<iostream>
#include 	<sys/types.h>
#include	<WinSock2.h>
#include	<windows.h>
#include	<stdio.h>
#include	"CWAbsUDPNetwork.h"

CWAbsUDPNetwork::CWAbsUDPNetwork()
{
  _port = 0;
  _broadcast = 0;
}

CWAbsUDPNetwork::~CWAbsUDPNetwork()
{

}

void	CWAbsUDPNetwork::setArg(char **argv)
{
  int	i;

  i = 1;
  while (argv[i])
    {
      if (strcmp(argv[i], PORT) == 0 && argv[i + 1])
	_port = atoi(argv[i + 1]);
      else if (strcmp(argv[i], BROADCAST) == 0 && argv[i + 1])
	_broadcast = argv[i + 1];
      i++;
    }

  if (_port == 0 || _broadcast == 0)
    {
      std::cout << USAGE << std::endl;
      exit(0);
    }
}

Socket CWAbsUDPNetwork::CreateSocket()
{
	WSADATA	wsadata;
	my_addr = new struct sockaddr_in;
	
	if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
	  {
	    std::cout << ERROR_INIT_SOCKET << std::endl;
	    exit(0);
	  }
	_socket = (void *)socket(AF_INET,SOCK_DGRAM,0);
	if ((int)_socket == INVALID_SOCKET)
	  {
	    std::cout << ERROR_CREATE_SOCKET << std::endl;
	    exit(0);
	  }
	else
	  std::cout << SOCKET_OK <<std::endl;

	my_addr->sin_family=AF_INET;
	my_addr->sin_addr.s_addr=inet_addr(_broadcast);
	my_addr->sin_port=htons(_port);
	return (0);
}

int   CWAbsUDPNetwork::Receive(void *Buffer)
{
	int ttl = 1;
	int a = sizeof(struct sockaddr);
	struct sockaddr_in addr_r;

	if (setsockopt((int)_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&ttl, sizeof(ttl)) < 0) 
	{
		std::cout << ERROR_RECV << std::endl;
		return (0);
	}
	return (recvfrom((int)_socket, (char *)Buffer, 500, 0, (struct sockaddr *)&addr_r, &a));
}

int   CWAbsUDPNetwork::Send(const void *Buffer, size_t size)
{
	int ttl = 1;
    if (setsockopt((int)_socket, SOL_SOCKET, SO_BROADCAST, (char *)&ttl, sizeof(int)) < 0)
    {
      std::cout << SETSOCK << std::endl;
      return (0);
    }

  if (sendto((int)_socket, (char *)Buffer, size, 0, (struct sockaddr *)my_addr, sizeof(struct sockaddr)) < 0)
	{  
		std::cout << ERROR_SEND << std::endl;
		return (0);
	}
  return (0);
}

int   CWAbsUDPNetwork::CloseSocket()
{
  CloseHandle((HANDLE) _socket);
  return (0);
}

void	CWAbsUDPNetwork::Bind()
{
	my_addr->sin_addr.s_addr=INADDR_ANY;
  if (bind((int)_socket,(struct sockaddr *)my_addr, sizeof(struct sockaddr_in)) < 0)
    {
      std::cout << ERROR_BIND << std::endl;
      exit(0);
    }
    std::cout << BIND_OK << std::endl;
	my_addr->sin_addr.s_addr=inet_addr(_broadcast);
}

#endif
