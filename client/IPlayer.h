#ifndef	IPLAYER_H
#define IPLAYER_H

class	IPlayer
{
 private:
  virtual int		_id = 0;
  virtual int		_life = 0;
  virtual int		_posx = 0;
  virtual int		_posy = 0;
 public:
  virtual void		Die() = 0;
  virtual void		Move(int x, int y) = 0;
  virtual void		Shoot() = 0;
};

#endif //!IPLAYER_H
