#ifndef _MONSTERFIVE_H_
# define _MONSTERFIVE_H_

<<<<<<< HEAD
#include "../Object.h"
=======
#include "../Session.h"
>>>>>>> 1c8dce1f72fb338bc3a4eb8cbf378fd68958646f

class	MonsterFive : public Object
{
 public:
  MonsterFive(char id, char x, char y, char type = 11);
  void	move(Session *s);
  ~MonsterFive();
  char getType();
};

typedef MonsterFive *(*maker_monster)(char id, char x, char y);

#endif // _MONSTERFIVE_H_
