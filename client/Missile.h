#ifndef MISSILE_H
#define MISSILE_H

#include "IWeapon.h"

class	Misille : public IWeapon
{
 private:
  int	_id;
  int	_power;
  int	_ammo;
  std::list<sf::Sprite>	_lShoot;
  std::list<sf::Sprite>	_lSprite;
  std::list<sf::Sound>	_lSound;
 public:
  Missile(std::list<sf::Image> &ImgWeapon, std::list<sf::SoundBuffer> &SoundWeapon);
  virtual void	Shoot();
  virtual void	Move();
};

#endif //!MISSILE_H
