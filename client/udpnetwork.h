#ifndef UDPNETWORK_H_
#define UDPNETWORK_H_

#define NBOCTETS 8
#include <SFML/Network.hpp>
#include <iostream>

class udpNetwork
{
 private:
  std::string	_ip;
  sf::UdpSocket	_socket;
  //  sf::SelectorUDP	_selector;
  int		_port;
 public:
  udpNetwork();
  ~udpNetwork();
  std::string&		getIP();
  int			getPort();
  sf::UdpSocket		&getSocket();
  //  sf::SelectorUDP	&getSelector();
  void			setIP(std::string& ip);
  void			setPort(int port);
  void			sendMessage(char buffer[NBOCTETS]);
};


#endif
