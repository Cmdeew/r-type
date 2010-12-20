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
  unsigned char	getId();
  unsigned char	getPosx();
  unsigned char	getPosy();
  unsigned char	getLife();
  
private:
  unsigned char	_id;
  unsigned char	_posx;
  unsigned char	_posy;
  unsigned char _life;
};

#endif
