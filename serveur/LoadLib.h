#ifndef LOADLIB_H_
# define LOADLIB_H_

#include "Factory.h"

class	LoadLib
{
 private:
  maker_monster tabMonster[9];
  AbsDynamicLib *l;
  std::string	file;
 public:
  maker_monster * getTab();
  bool	ifLib(const std::string name);
  void	initTabMonster();
  void	checkLib();
  void	fillTab(maker_monster pMonster);
  LoadLib();
  ~LoadLib();  
};

#endif // LOADLIB_H_
