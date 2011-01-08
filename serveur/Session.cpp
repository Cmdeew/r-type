#include "Session.h"
#include <stdlib.h>

Session::Session(AbsUDPNetwork *p, AbsThread *th, AbsMutex *mt, int nbGame)
{
  std::vector<Player *>     tabPlayer(4);
  _tabPlayer = tabPlayer;
  _p = p;
  std::cout << (int)_p->_socket << std::endl;
  _th = th;
  _mt = mt;
  _pingTime[0] = 0;
  _pingTime[1] = 0;
  _pingTime[2] = 0;
  _pingTime[3] = 0;
  _game_n = nbGame;
  _score = 0;
}


Session::~Session()
{
}


void  Session::sessionthread()
{
  int cc;
  char buffer[6];
  int session = _session_n;
  Command           cmd(_game_n);

  _pingTime[session] = MAX_PING_TIME;
  _tabPlayer[session] = new Player(session +1);
  std::cout << "New player assign on slot " << session << "... Partie " << _game_n << std::endl;
  cmd.sendConnect(_tabPlayer[session], _p);
  cmd.sendLife(_tabPlayer[session], _p);
  //  cmd.sendMove(_tabPlayer[session], _p);
  //  std::cout << "En attente des nouvelles positions du client..." << std::endl;
  while (_pingTime[session] > 0)
    {
      //Pas de recv dans les threads
      //Le recv est gerer dans la boucle principal en dehors des threads

      //Ici c' est la boucle du thread
      //Lis dans le _tabPlayer et autre et envoit les infos avec _cmd.send****(***)
      //A 20 tours de boucles On fait un ping avec _cmd.sendPing()
      //Si la boucle recv principal ne recoit rien, on deco et on kill la thread
      
   if (_pingTime[session] % 100 == 0)
	cmd.sendMove(_tabPlayer[session], _p);

   if (_pingTime[session] == MID_PING_TIME)
	{
	  cmd.sendPing(_tabPlayer[session], _p);
	  std::cout << "Sending ping to client (player " << session + 1 << ")..." << std::endl;
	}
      if (_pingTime[session] == WARN_PING_TIME)
	{
	  cmd.sendPing(_tabPlayer[session], _p);
	  std::cout << "Sending ping to client (player " << session + 1 << ") (WARNING LAST PING BEFORE DISCONNECT)..." << std::endl;
	}
      _pingTime[session] -= 1;
      _th->ASleep(500);
    }
  cmd.sendDestroy(_tabPlayer[session]->getId(), 0,  _p);
  cmd.sendDisconnect(_tabPlayer[session], _p);
  std::cout << "Disconnecting client (player " << session + 1 << ") on slot " << session << "." << std::endl;
  std::cout << "The slot " << session << " is now free." << std::endl;
  _th->AExitThread(handles[session]);
}

void  Session::sessionthreadElems()
{
  int i = 0;
  int a = 0;
  Command           cmd(_game_n);
  Object	*obj;
  Object	*obj2;
  std::list<Object *>::iterator it;
  std::list<Object *>::iterator it2;

  //creer la liste des objs tout les x secondes et setter leur positions
  //Mettre une liste d'obj dans la classe Session List<Object> listObj;
  //      obj = new Object(5, 46, 16, 11);
  static unsigned char mob_id = 10; // TO CHANGE
  std::cout << "Success for threadElems" << std::endl;
  while (1) // On envoie des elements à l'infini
    {
      if (i == 10000)
	i = 0;

      //Generation d'un mob
      if (i% 9999)
	{
	  a = rand();
	  if (a % 500 == 0) //2000
	    {
	      //	      obj = new Object(mob_id++, 55, 16, 12);
	      obj = new Object(mob_id++, 55, rand() % 16, (rand() % 2) + 11);
	      _listObj.push_back(obj);
	      if (mob_id > 45)
		mob_id = 10;
	    }
	}

      if (i % 100 == 0)
	{
	  //Detection des collisions
	  it = _listObj.begin();
	  while (it != _listObj.end())
	    {
	      it2 = _listObj.begin();
	      while (it2 != _listObj.end())
		{
		  obj = *it;
		  obj2 = *it2;
		  if ((obj != obj2) &&
			obj->getX() < obj2->getX() + 3 && obj->getX() > obj2->getX() - 3 &&
			obj->getY() < obj2->getY() + 3 && obj->getY() > obj2->getY() - 3)
		    {
		      cmd.sendDestroy(obj->getId() , obj2->getId(), _p); 
		      _listObj.erase(it);
		      _listObj.erase(it2);
		      //obj = new Object(6, 55, 16, 11 + ((int)rand() %2));
		      //_listObj.push_back(obj);
		      it = _listObj.begin();
		      it2 = _listObj.begin();
		    }
		  it2++;
		}
	      it++;
	    }


	  // Fin detection des collisions
	  it = _listObj.begin();
	  while (it != _listObj.end())
	    {
	      obj = *it;
	      if (obj->getType() == 5 || obj->getType() == 6)
		{
		  obj->move(); //Mouvement des missiles
		  cmd.sendObjMove(obj, _p); //TEST
		  if (obj->getX() > 50) //Missile depassant la fenetre
		    {
		      cmd.sendDestroy(obj->getId() , 0, _p);
		      _listObj.erase(it);
		      it = _listObj.begin();
		    }
		}
	      it++;
	    }
	}

      // Debut collision player ++ mob

      if (i % 100 == 0)
	{
	  int   j;
          it = _listObj.begin();
          while (it != _listObj.end())
            {
              j = 0;
	      obj = *it;
              while (j <= 3)
                {
		  if (_tabPlayer[j] != NULL && obj->getType() != 5 && 
                      obj->getX() < _tabPlayer[j]->getPosx() + 3 && obj->getX() > _tabPlayer[j]->getPosx() - 3 &&
                      obj->getY() < _tabPlayer[j]->getPosy() + 3 && obj->getY() > _tabPlayer[j]->getPosy() - 3)
                    {
		      std::cout << "Collision" << std::endl;
		      if ((_tabPlayer[j]->getLife() - 1) > 0)
                        {
                          _tabPlayer[j]->setLife(_tabPlayer[j]->getLife() - 1);
                          cmd.sendLife(_tabPlayer[j], _p);
			  _tabPlayer[j]->setPosx(10);
			  _tabPlayer[j]->setPosy(10);
                        }
                      else
                        _pingTime[j] = 0;
                    }
                  j++;
                }
              it++;
            }
	}

      // Fin collision player ++ mob

      if (i % 200 == 0)
	{
	  std::cout << "Sending each objs position" << std::endl;
	  it = _listObj.begin();
	  while (it != _listObj.end())
	    {
	      obj = *it;
	      obj->move();
	      cmd.sendObjMove(obj, _p);
	      if (obj->getX() == 0) // depassant la fenetre
		{
		  cmd.sendDestroy(obj->getId() , 0, _p);
		  _listObj.erase(it);
		  it = _listObj.begin();
		}
	      it++;
	    }
	}
      _th->ASleep(500);
      i++;
    }
}


void	*Session::sessionthreadElemsInit(Session *sess)
{
  sess->sessionthreadElems();
  return (NULL);
}

void	*Session::sessionthreadInit(Session *sess)
{
  sess->sessionthread();
  return (NULL);
}
