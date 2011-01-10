#ifndef _CUABSDYNAMICLIB_H_
# define _CUABSDYNAMICLIB_H_

#ifndef _WIN32

// Inclusion des header de chaque libs

#include <dirent.h>
#include "./inc/UMonsterOne.h"
#include "AbsDynamicLib.h"

// Define de chaque monstre

#define	MONSTERONE	"MonsterOne.so"
#define	MONSTERTWO	"MonsterTwo.so"
#define	MONSTERTHREE	"MonsterThree.so"
#define	MONSTERFOUR	"MonsterFour.so"
#define	MONSTERFIVE	"MonsterFive.so"
#define	MONSTERSIX	"MonsterSix.so"
#define	MONSTERSEVEN	"MonsterSeven.so"
#define	MONSTERHEIGHT	"MonsterHeight.so"
#define	MONSTERNINE	"MonsterNine.so"


class	CUAbsDynamicLib : public AbsDynamicLib
{
 public:
  hand	AOpenLib(pstr name);
  bool	ACloseLib(hand lib);
  addr	ASymLib(hand lib, const char *symbol);
  CUAbsDynamicLib();
  ~CUAbsDynamicLib();
};
#endif

#endif //_CUABSDYNAMICLIB_H_
