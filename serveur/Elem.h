#ifndef _ELEM_H_
# define _ELEM_H_

#include "Object.h"

class	Elem : public Object
{
public:
  Elem();
  Elem(char id, char x, char y, char type);
  ~Elem();
  void	move();
};

#endif // _ELEM_H_
