#ifndef _PLAYER_H_
#define _PLAYER_H_


class	Player
{
public:
  Player();
  Player(unsigned char id);
  ~Player();
  void	setId(unsigned char id);
  void	setPosx(unsigned char x);
  void	setPosy(unsigned char y);
  void	setLife(unsigned char life);
  void	setTLife(int tLife);
  unsigned char	getId();
  unsigned char	getPosx();
  unsigned char	getPosy();
  unsigned char	getLife();
  int		getTLife();
private:
  unsigned char	_id;
  unsigned char	_posx;
  unsigned char	_posy;
  unsigned char _life;
  int		_timeLife;
};

#endif
