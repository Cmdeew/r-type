#include "Factory.h"
#include "Command.h"
#include "Session.h"
#include "Game.h"

Game::Game(Factory *_f, char **argv)
{
  f = _f;
  th = f->n_thread();
  p = f->n_network();
  p->setArg(argv);
  p->CreateSocket();
  p->Bind();
  

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
  Session *session = new Session(p, th, id);
  Command cmd(id);

  while (1)
    cmd.receiveFromClient(session, p);
}

void *Game::startMultiGame(Game *g)
{
  g->startGame(g->id);
  return (NULL);
}
