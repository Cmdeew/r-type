#include <iostream>
#include "udpnetwork.h"

udpNetwork::udpNetwork()
{
  ;
}

udpNetwork::~udpNetwork()
{
  ;
}

int		udpNetwork::getBindPort()
{
  return(_bind_port);
}

int		udpNetwork::getServerPort()
{
  return(_server_port);
}

std::string&	udpNetwork::getServerIP()
{
  return(_server_ip);
}

sf::UdpSocket	&udpNetwork::getSocket()
{
  return(_socket);
}

int udpNetwork::bind()
{
  return _socket.bind(_bind_port);
}

void			udpNetwork::setBindPort(int port)
{
  _bind_port = port;
}

void			udpNetwork::setServerPort(int port)
{
  _server_port = port;
}

void			udpNetwork::setServerIP(std::string& ip)
{
  _server_ip = ip;
}

void			udpNetwork::sendMessage(char buffer[NBOCTETS])
{
  if(_socket.send(buffer, NBOCTETS, this->getServerIP(), this->getServerPort())
     !=  sf::Socket::Done)
    std::cout << "Error: Socket send." << std::endl;
}
