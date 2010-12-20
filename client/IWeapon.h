#ifndef IWEAPON_H
#define IWEAPON_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

class	IWeapon
{
 private:
  virtual int	_id = 0;
  virtual int	_power = 0;
  virtual int	_ammo = 0;
  virtual std::list<sf::Sprite>	_lShoot = 0;
  virtual std::list<sf::Sprite>	_lSprite = 0;
  virtual std::list<sf::Sound>	_lSound = 0;
 public:
  virtual void	Shoot() = 0;
  virtual void	Move() = 0;
};

#endif //IWEAPON_H
