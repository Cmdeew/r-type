#include "Factory.h"
#include "Command.h"
#include "Session.h"
#include "Game.h"
#include "Object.h"
#include "LoadLib.h"

Game::Game(Factory *_f, char **argv)
{
  AbsUDPNetwork *p1;
  AbsUDPNetwork *p2;
  LoadLib	*lib;
  Socket	 sock;
  Socket	 sock1;
  Socket	 sock2;

  f = _f;
  th = f->n_thread();
  mt = f->n_mutex();
  p = f->n_network();
  p1 = f->n_network();
  p2 = f->n_network();
  p->setArg(argv);
  sock = p->CreateSocket(p->getPort());
  p->Bind(sock);
  p1->setArg(argv);
  sock1 = p1->CreateSocket(p->getPort()+1);
  p1->Bind(sock1);
  p2->setArg(argv);
  sock2 = p2->CreateSocket(p->getPort() + 2);
  p2->Bind(sock2);
  s = new Session * [3];
  s[0] = new Session(p, th, mt, 1);
  s[1] = new Session(p1, th, mt, 2);
  s[2] = new Session(p2, th, mt, 3);
  lib = new LoadLib();
  lib->initTabMonster();
  lib->checkLib();
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
    cmd.receiveFromClient(s[id - 1], s[id - 1]->_p);
}

void *Game::startMultiGame(Game *g)
{
  g->startGame(g->id);
  return (NULL);
}
