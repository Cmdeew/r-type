#ifndef ELEMENT_H_
#define ELEMENT_H

class Element
{
 private:
  unsigned char	     	_posX;
  unsigned char	       	_posY;
  unsigned char		_life;
  unsigned char		_ID;
  unsigned char		_type;
  Element();
 public:
  Element(unsigned char x, unsigned char y, unsigned char life,
	  unsigned char id, unsigned char type);
  ~Element();
  void			setPosX(unsigned char);
  void			setPosY(unsigned char);
  void			setLife(unsigned char);
  void			setID(unsigned char);
  void			setType(unsigned char);
  unsigned char&	getPosX();
  unsigned char&	getPosY();
  unsigned char&	getLife();
  unsigned char&	getID();
  unsigned char&	getType();
};

#endif
