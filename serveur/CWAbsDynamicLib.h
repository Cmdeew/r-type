#ifndef _CWABSDYNAMICLIB_H_
# define _CWABSDYNAMICLIB_H_

#ifdef _WIN32
#include "./inc/WMonsterOne.h"
#include "AbsDynamicLib.h"
#include "dirent.h"

#define	MONSTERONE	"MonsterOne.dll"
#define	MONSTERTWO	"MonsterTwo.dll"
#define	MONSTERTHREE	"MonsterThree.dll"
#define	MONSTERFOUR	"MonsterFour.dll"
#define	MONSTERFIVE	"MonsterFive.dll"
#define	MONSTERSIX	"MonsterSix.dll"
#define	MONSTERSEVEN	"MonsterSeven.dll"
#define	MONSTERHEIGHT	"MonsterHeight.dll"
#define	MONSTERNINE	"MonsterNine.dll"

class	CWAbsDynamicLib : public AbsDynamicLib
{
 public:
  hand	AOpenLib(pstr name);
  bool	ACloseLib(hand lib);
  addr	ASymLib(hand lib, const char *symbol);
  CWAbsDynamicLib();
  ~CWAbsDynamicLib();
};
#endif

#endif //_CUABSTHREAD_H_
