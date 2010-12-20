#include "udpnetwork.h"
#include <iostream>

udpNetwork::udpNetwork()
{
  ;
}

udpNetwork::~udpNetwork()
{
  ;
}

int		udpNetwork::getPort()
{
  return(_port);
}

std::string&	udpNetwork::getIP()
{
  return(_ip);
}

sf::SocketUDP	&udpNetwork::getSocket()
{
  return(_socket);
}

sf::SelectorUDP	&udpNetwork::getSelector()
{
  return(_selector);
}

void			udpNetwork::setPort(int port)
{
  _port = port;
}

void			udpNetwork::setIP(std::string& ip)
{
  _ip = ip;
}

void			udpNetwork::sendMessage(char buffer[NBOCTETS])
{
  if(_socket.Send(buffer, NBOCTETS, this->getIP(), this->getPort())
     !=  sf::Socket::Done)
    std::cout << "Error: Socket send." << std::endl;
}
