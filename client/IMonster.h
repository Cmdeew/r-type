#ifndef IMONSTER_H
#define IMONSTER_H

class	IMonster
{
 private:
  virtual int	_id = 0;
  virtual int	_life = 0;
 public:
  virtual void	Shoot() = 0;
  virtual void	Move() = 0;
  virtual void	Die() = 0;

};

#endif //IMONSTER_H
