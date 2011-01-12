#ifndef LOADLIB_H_
# define LOADLIB_H_

#include "inc/UMonsterOne.h"
#include "Object.h"
#include "Factory.h"

class	LoadLib
{
 private:
  maker_monster tabMonster[9];
  AbsDynamicLib *l;
  std::string	file;
  void          *hnd1;
 public:
  maker_monster getMaillon(int nb);
  Object* getInstance(int nb, char id, char x, char y);
  bool	ifLib(const std::string name);
  void	initTabMonster();
  void	checkLib();
  void	fillTab(maker_monster pMonster);
  void	freeLib();
  LoadLib();
  ~LoadLib();  
};

#endif // LOADLIB_H_
