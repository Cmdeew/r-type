#ifndef UDPNETWORK_H_
#define UDPNETWORK_H_

#define NBOCTETS 6
#include "SFML/include/Network.hpp"
#include <iostream>

class udpNetwork
{
 private:
  std::string	_ip;
  sf::SocketUDP	_socket;
  sf::SelectorUDP	_selector;
  int		_port;
 public:
  udpNetwork();
  ~udpNetwork();
  std::string&		getIP();
  int			getPort();
  sf::SocketUDP		&getSocket();
  sf::SelectorUDP	&getSelector();
  void			setIP(std::string& ip);
  void			setPort(int port);
  void			sendMessage(char buffer[NBOCTETS]);
};


#endif
