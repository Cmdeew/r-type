#ifndef UDPNETWORK_H_
#define UDPNETWORK_H_

#define NBOCTETS 8
#include <SFML/Network.hpp>
#include <iostream>

class udpNetwork
{
 private:
  std::string	_server_ip;
  sf::UdpSocket	_socket;
  int		_server_port;
  int    	_bind_port;
 public:
  udpNetwork();
  ~udpNetwork();
  std::string&		getServerIP();
  int			getServerPort();
  int			getBindPort();
  sf::UdpSocket		&getSocket();
  int             bind();
  void			setServerIP(std::string& ip);
  void			setServerPort(int port);
  void			setBindPort(int port);
  void			sendMessage(char buffer[NBOCTETS]);
};


#endif
