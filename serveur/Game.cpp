#include "Factory.h"
#include "Command.h"
#include "Session.h"
#include "Game.h"

Game::Game(Factory *_f, char **argv)
{
  AbsUDPNetwork *p1;
  AbsUDPNetwork *p2;

  f = _f;
  th = f->n_thread();
  mt = f->n_mutex();
  p = f->n_network();
  p->setArg(argv);
  p->CreateSocket();
  p->Bind();

  s = new Session * [3];
  s[0] = new Session(p, th, mt, 1);
  s[1] = new Session(p, th, mt, 2);
  s[2] = new Session(p, th, mt, 3);
  s[0]->_mt->AMutexInit(&priority);
}

Game::~Game()
{

}

void Game::setId(int _id)
{
  id = _id;
}

void Game::startGame(int id)
{
  Command	cmd(id);

  std::cout << "Partie : " << id << std::endl;
  while (1)
    cmd.receiveFromClient(s[id - 1], p, &priority);
}

void *Game::startMultiGame(Game *g)
{
  g->startGame(g->id);
  return (NULL);
}
