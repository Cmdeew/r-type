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
  std::list<sf::Texture>	_lplayer1;
  std::list<sf::Texture>	_lplayer2;
  std::list<sf::Texture>	_lplayer3;
  std::list<sf::Texture>	_lplayer4;
  std::list<sf::Texture>	_lweapon1;
  std::list<sf::Texture>	_lweapon2;
  std::list<sf::Texture>	_lweapon3;
  std::list<sf::Texture>	_lweapon4;
  std::list<sf::Texture>	_lweapon5;
  std::list<sf::Texture>	_lweapon6;
  std::list<sf::Texture>	_lmeteor1;
  std::list<sf::Texture>	_ledge1;
  std::list<sf::Texture>	_lwall1;
  std::list<sf::Texture>	_lwall2;
  std::list<sf::Texture>	_lwall3;
  std::list<sf::Texture>	_lwall4;
  std::list<sf::Texture>	_lwall5;
  std::list<sf::Texture>	_lmonster1;
  std::list<sf::Texture>	_lmonster2;
  std::list<sf::Texture>	_lmonster3;
  std::list<sf::Texture>	_lmonster4;
  std::list<sf::Texture>	_lmonster5;
  std::list<sf::Texture>	_lmonster6;
  std::list<sf::Texture>	_lmonster7;
  std::list<sf::Texture>	_lmonster8;
  std::list<sf::Texture>	_lmonster9;
  std::list<sf::Texture>	_lboss1;
  std::list<sf::Texture>	_lboss2;
  std::list<sf::Texture>	_lboss3;
  std::list<sf::Texture>	_lboss4;
  std::list<sf::Texture>	_lexplo1;
std::list<sf::Texture>	_lastronaute1;
 std::list<sf::Texture>	_llife1;
  
 public:
  ImageCenter();
  const std::list<sf::Texture>	&getLplayer1() const;
  const std::list<sf::Texture>	&getLplayer2() const;
  const std::list<sf::Texture>	&getLplayer3() const;
  const std::list<sf::Texture>	&getLplayer4() const;
  const std::list<sf::Texture>	&getLweapon1() const;
  const std::list<sf::Texture>	&getLweapon2() const;
  const std::list<sf::Texture>	&getLweapon3() const;
  const std::list<sf::Texture>	&getLweapon4() const;
  const std::list<sf::Texture>	&getLweapon5() const;
  const std::list<sf::Texture>	&getLweapon6() const;
  const std::list<sf::Texture>	&getLmeteor1() const;
  const std::list<sf::Texture>	&getLedge1() const;
  const std::list<sf::Texture>	&getLwall1() const;
  const std::list<sf::Texture>	&getLwall2() const;
  const std::list<sf::Texture>	&getLwall3() const;
  const std::list<sf::Texture>	&getLwall4() const;
  const std::list<sf::Texture>	&getLwall5() const;
  const std::list<sf::Texture>	&getLmonster1() const;
  const std::list<sf::Texture>	&getLmonster2() const;
  const std::list<sf::Texture>	&getLmonster3() const;
  const std::list<sf::Texture>	&getLmonster4() const;
  const std::list<sf::Texture>	&getLmonster5() const;
  const std::list<sf::Texture>	&getLmonster6() const;
  const std::list<sf::Texture>	&getLmonster7() const;
  const std::list<sf::Texture>	&getLmonster8() const;
  const std::list<sf::Texture>	&getLmonster9() const;
  const std::list<sf::Texture>	&getLboss1() const;
  const std::list<sf::Texture>	&getLboss2() const;
  const std::list<sf::Texture>	&getLboss3() const;
  const std::list<sf::Texture>	&getLboss4() const;
  const std::list<sf::Texture>	&getLexplo1() const;
  const std::list<sf::Texture>	&getLastronaute1() const;
 const std::list<sf::Texture>	&getLlife1() const;
};

#endif //!IMAGECENTER_H
