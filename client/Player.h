#ifndef PLAYER_H
#define PLAYER_H

template<typename MyWeapon>
class	Player
{
 private:
  int	_id;
  int	_life;
  int	_posx;
  int	_posy;
  MyWeapon	*_weapon;
 public:
  void	Die();
  void	Move(int x, int y);
  void	Shoot();
};


#endif //!PLAYER_H
