#include <sys/types.h>
#include "LoadLib.h"

void	LoadLib::freeLib()
{
  l->ACloseLib(hnd1);
}

maker_monster LoadLib::getMaillon(int nb)
{
  return (tabMonster[nb]);
}

Object *LoadLib::getInstance(int nb, char id, char x, char y)
{
  Object *save;

  save = tabMonster[nb](id, x, y);
  return (save);
}

void LoadLib::initTabMonster()
{
  int	i;

  i = 0;
  while (i < 9)
    {
      tabMonster[i] = NULL;
      i++;
    }
}

void LoadLib::fillTab(maker_monster pMonster)
{
	
  if (file.compare(MONSTERONE) == 0)
    tabMonster[0] = pMonster;
  else if (file.compare(MONSTERTWO) == 0)
    tabMonster[1] = pMonster;
  else if (file.compare(MONSTERTHREE) == 0)
    tabMonster[2] = pMonster;
  else if (file.compare(MONSTERFOUR) == 0)
    tabMonster[3] = pMonster;
  else if (file.compare(MONSTERFIVE) == 0)
    tabMonster[4] = pMonster;
  else if (file.compare(MONSTERSIX) == 0)
    tabMonster[5] = pMonster;
  else if (file.compare(MONSTERSEVEN) == 0)
    tabMonster[6] = pMonster;
  else if (file.compare(MONSTERHEIGHT) == 0)
    tabMonster[7] = pMonster;
  else if (file.compare(MONSTERNINE) == 0)
    tabMonster[8] = pMonster;
}

bool LoadLib::ifLib(const std::string name)
{
  if (name.compare(MONSTERONE) == 0)
    return (true);
  else if (name.compare(MONSTERTWO) == 0)
    return (true);
  else if (name.compare(MONSTERTHREE) == 0)
    return (true);
  else if (name.compare(MONSTERFOUR) == 0)
    return (true);
  else if (name.compare(MONSTERFIVE) == 0)
    return (true);
  else if (name.compare(MONSTERSIX) == 0)
    return (true);
  else if (name.compare(MONSTERSEVEN) == 0)
    return (true);
  else if (name.compare(MONSTERHEIGHT) == 0)
    return (true);
  else if (name.compare(MONSTERNINE) == 0)
    return (true);
  return (false);
}

void LoadLib::checkLib()
{
  DIR           *dir;
  struct dirent *ls;
  std::string   name;
  Object        *obj;
  int		i = 0;

  if ((dir = opendir("./lib")) != NULL)
    {
      while ((ls = readdir(dir)) != NULL)
        {
          name.assign(ls->d_name);
	  file.assign(ls->d_name);
	  if (this->ifLib(name) == true)
	    {
		  name.insert(0, "./lib/");
		  std::cout << name.c_str() << std::endl;
	      if (hnd1 != NULL)
		{
		  void *mkr = l->ASymLib(hnd1, "Create");
		  if (mkr != NULL)
		    {
		      std::cout << "succes !" << std::endl;
		      this->fillTab((maker_monster)mkr);
		    }
		  else
		    this->fillTab(NULL);
		  //l->ACloseLib(hnd1);
		}
	      else
		std::cout << "Lib incorrect" << std::endl;
	    }
        }
    }
}

LoadLib::LoadLib()
{
  Factory *f;

  f = new Factory();
  l = f->n_lib();
}

LoadLib::~LoadLib()
{
  
}
