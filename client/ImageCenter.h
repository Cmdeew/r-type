#ifndef	IMAGECENTER_H
#define IMAGECENTER_H

#include <iostream>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class	ImageCenter
{
 private:
  std::list<sf::Image>	_lplayer1;
  std::list<sf::Image>	_lplayer2;
  std::list<sf::Image>	_lplayer3;
  std::list<sf::Image>	_lplayer4;
  std::list<sf::Image>	_lweapon1;
  std::list<sf::Image>	_lweapon2;
  std::list<sf::Image>	_lmeteor1;
  std::list<sf::Image>	_ledge1;
  std::list<sf::Image>	_lmonster1;
  std::list<sf::Image>	_lmonster2;
  std::list<sf::Image>	_lmonster3;
  std::list<sf::Image>	_lmonster4;
  std::list<sf::Image>	_lmonster5;
  std::list<sf::Image>	_lmonster6;
  std::list<sf::Image>	_lmonster7;
  std::list<sf::Image>	_lmonster8;
  std::list<sf::Image>	_lmonster9;
  std::list<sf::Image>	_lboss1;
  std::list<sf::Image>	_lboss2;
  std::list<sf::Image>	_lboss3;
  std::list<sf::Image>	_lexplo1;
 public:
  ImageCenter();
  const std::list<sf::Image>	&getLplayer1() const;
  const std::list<sf::Image>	&getLplayer2() const;
  const std::list<sf::Image>	&getLplayer3() const;
  const std::list<sf::Image>	&getLplayer4() const;
  const std::list<sf::Image>	&getLweapon1() const;
  const std::list<sf::Image>	&getLweapon2() const;
  const std::list<sf::Image>	&getLmeteor1() const;
  const std::list<sf::Image>	&getLedge1() const;
  const std::list<sf::Image>	&getLmonster1() const;
  const std::list<sf::Image>	&getLmonster2() const;
  const std::list<sf::Image>	&getLmonster3() const;
  const std::list<sf::Image>	&getLmonster4() const;
  const std::list<sf::Image>	&getLmonster5() const;
  const std::list<sf::Image>	&getLmonster6() const;
  const std::list<sf::Image>	&getLmonster7() const;
  const std::list<sf::Image>	&getLmonster8() const;
  const std::list<sf::Image>	&getLmonster9() const;
  const std::list<sf::Image>	&getLboss1() const;
  const std::list<sf::Image>	&getLboss2() const;
  const std::list<sf::Image>	&getLboss3() const;
  const std::list<sf::Image>	&getLexplo1() const;
};

#endif //!IMAGECENTER_H
