#ifndef	_WIN32

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include	"CUAbsUDPNetwork.h"

CUAbsUDPNetwork::CUAbsUDPNetwork()
{
  _port = 0;
  _broadcast = 0;
}

void	CUAbsUDPNetwork::setArg(char **argv)
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

Socket	CUAbsUDPNetwork::CreateSocket(int port)
{
  my_addr = new struct sockaddr_in;
  if ((_socket=(void *)socket(AF_INET,SOCK_DGRAM,0)) < 0)
    {
      std::cout << ERROR_CREATE_SOCKET << std::endl;
      exit(0);
    }                                                                          
  memset(my_addr,0,sizeof(my_addr));
  my_addr->sin_family=AF_INET;
  my_addr->sin_addr.s_addr=inet_addr(_broadcast);
  my_addr->sin_port=htons(port);
  std::cout << SOCKET_OK << std::endl;
  return (_socket);
}

int	CUAbsUDPNetwork::Receive(void *Buffer)
{ 
  int ttl = 1;
  int a =  sizeof(struct sockaddr);
  struct sockaddr_in addr_r;

  if (setsockopt((int)_socket,SOL_SOCKET,SO_REUSEADDR,&ttl,sizeof(ttl)) < 0) 
  {
    std::cout << "Error" << std::endl;
    return (0);
  }
  return (recvfrom((int)_socket, Buffer, CMD_SIZE, 0, (struct sockaddr *)&addr_r, (socklen_t *)&a));
}

int	CUAbsUDPNetwork::Send(const void *Buffer, size_t size)
{
  int ttl = 1;
  if (setsockopt((int)_socket, SOL_SOCKET, SO_BROADCAST, &ttl, sizeof(int)) < 0)
    {
      std::cout << SETSOCK << std::endl;
      exit(0);
    }
  if (sendto((int)_socket, Buffer, size, 0, (struct sockaddr *)my_addr, sizeof(struct sockaddr)) < 0)
    std::cout << ERROR_SEND << std::endl;
}

int	CUAbsUDPNetwork::CloseSocket()
{
  close((int)_socket);
}

void	CUAbsUDPNetwork::Bind(Socket sock)
{
  my_addr->sin_addr.s_addr=htonl(INADDR_ANY);
  if (bind((int)sock, (struct sockaddr *)my_addr, sizeof(struct sockaddr_in)))
   {
      std::cout << ERROR_BIND << std::endl;
      exit(0);
   }
  my_addr->sin_addr.s_addr=inet_addr(_broadcast);
  std::cout << BIND_OK << std::endl;
}

CUAbsUDPNetwork::~CUAbsUDPNetwork()
{

}

#endif
