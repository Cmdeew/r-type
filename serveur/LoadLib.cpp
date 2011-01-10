#include <sys/types.h>
#include <dirent.h>
#include "LoadLib.h"
#include "Object.h"

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
  if (file == MONSTERONE)
    tabMonster[0] = pMonster;
  else if (file == MONSTERTWO)
    tabMonster[1] = pMonster;
  else if (file == MONSTERTHREE)
    tabMonster[2] = pMonster;
  else if (file == MONSTERFOUR)
    tabMonster[3] = pMonster;
  else if (file == MONSTERFIVE)
    tabMonster[4] = pMonster;
  else if (file == MONSTERSIX)
    tabMonster[5] = pMonster;
  else if (file == MONSTERSEVEN)
    tabMonster[6] = pMonster;
  else if (file == MONSTERHEIGHT)
    tabMonster[7] = pMonster;
  else if (file == MONSTERNINE)
    tabMonster[8] = pMonster;
}

bool LoadLib::ifLib(const std::string name)
{
  if (name == MONSTERONE)
    return (true);
  else if (name == MONSTERTWO)
    return (true);
  else if (name == MONSTERTHREE)
    return (true);
  else if (name == MONSTERFOUR)
    return (true);
  else if (name == MONSTERFIVE)
    return (true);
  else if (name == MONSTERSIX)
    return (true);
  else if (name == MONSTERSEVEN)
    return (true);
  else if (name == MONSTERHEIGHT)
    return (true);
  else if (name == MONSTERNINE)
    return (true);
  return (false);
}

void LoadLib::checkLib()
{
  DIR           *dir;
  struct dirent *ls;
  std::string   name;
  Object        *obj;
  void          *hnd1;
  int		i = 0;

  if ((dir = opendir("./lib")) != NULL)
    {
      while ((ls = readdir(dir)) != NULL)
        {
          name.assign(ls->d_name);
	  file.assign(ls->d_name);
	  if (this->ifLib(name) == true)
	    {
	      name = "./" +  name;
	      std::cout << name << std::endl;
	      hnd1 = l->AOpenLib((char *)name.c_str());
	      if (hnd1 != NULL)
		{
		  void *mkr = l->ASymLib(hnd1, "Create");
		  if (mkr != NULL)
		    this->fillTab((maker_monster)mkr);
		  else
		    this->fillTab(NULL);
		}
	      else
		std::cout << "Lib incorrect" << std::endl;
	    }
        }
    }
  while (i <= 8)
    {
      if (tabMonster[i] != NULL)
	std::cout << "Youpi !" << std::endl;
      i++;
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
