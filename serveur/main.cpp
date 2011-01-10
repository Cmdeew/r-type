#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "Factory.h"
#include "Game.h"

int	main(int ac, char **argv)
{
  (void) ac;
  Game	*start;
  int	i;

  i = 1;
  start = new Game(new Factory(), argv);
  srand(time(NULL));
  while (i <= 3)
    {
      start->setId(i);
      start->handles[i] = start->th->ACreateThread(&start->threads[i], NULL, (typefunc)start->startMultiGame, start);
      i++;
      start->th->ASleep(10000);
    }
  pause();
  //  while (42);
    //start->setId(0);
    //start->startMultiGame(start);
}
