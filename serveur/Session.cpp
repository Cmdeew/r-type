#include "LoadLib.h"
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
  mob_id = 11;
}


Session::~Session()
{
}


void  Session::sessionthread()
{
  int session = _session_n;
  Command           cmd(_game_n);

  _pingTime[session] = MAX_PING_TIME;
  _tabPlayer[session] = new Player(session +1);
  std::cout << "New player assign on slot " << session << "... Partie " << _game_n << std::endl;
  spawnPlayer(_tabPlayer[session]);
  cmd.sendConnect(_tabPlayer[session], _p);
  cmd.sendLife(_tabPlayer[session], _p);
  cmd.sendScore(_score, _p);
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

void	Session::Create_Mob(int i)
{
  
  Object	*obj;
  static int a = 0;
  static int nb = 0;
  static LoadLib * lib;


  if (nb == 0)
    {
      lib = new LoadLib();
      lib->initTabMonster();
      lib->checkLib();
      nb = 1;
    }

   //Generation d'un mob
  if (i% 9999)
    {
      //a = rand();
      
      //generation mob 12 BOULE
      static int b = 0;
      int r;
      if (a % 1000 == 0 && _score < LEVEL1)
	{
	  if (lib->getMaillon(1) != NULL)
	    {
	      r = rand();
	      if (b % 2 == 0 && r > 11)
		{
		  obj = lib->getInstance(1, mob_id++, 55, r%MAXRAND);
		  _listObj.push_back(obj);
		}
	      if (mob_id > 127)
		mob_id = 11;
	    }
	  b++;
	  if (b == 30)
	    b = 0;
	}

      //generation mob_14 AVION
      static int c = 0;
      if (a % 1000 == 0 && _score < LEVEL1)
	{
	  if (lib->getMaillon(3) != NULL)
	    {
	      if (c % 2 == 0)
		{
		  obj = lib->getInstance(3, mob_id++, 55, rand()%MAXRAND);
		  _listObj.push_back(obj);
		}
	      if (mob_id > 127)
		mob_id = 11;
	    }
	  c++;
	  if (c == 30)
	    c = 0;
	}
      
	  //generation mob_11
	  if (a % 6000 == 0 && _score > 2500)
	    {
	      if (lib->getMaillon(0) != NULL)
		  {
		    obj = lib->getInstance(0, mob_id++, 55, 20);
		    _listObj.push_back(obj);
		    if (mob_id > 127)
		      mob_id = 11;
		  }
	    }


	  //generation mob_13
	  if (a % 6000 == 0 && _score > 2500)
	    {
	      if (lib->getMaillon(2) != NULL)
		  {
		    obj = lib->getInstance(2, mob_id++, 55, 25);
		    _listObj.push_back(obj);
		    if (mob_id > 127)
		      mob_id = 11;
		  }
	    }
	  
	  //generation mob_9 MUR

	  /*if (a % 10000 == 0)
	    {
	      int j;
	      j = 0;
	      while (j < 3)
		{
		   obj = new Object(mob_id++, 55, 0+i*2, 9);
		  _listObj.push_back(obj);
		  if (mob_id > 127)
		    mob_id = 11;
		  obj = new Object(mob_id++, 55, 34-i*2, 9);
		  _listObj.push_back(obj);
		  if (mob_id > 127)
		    mob_id = 11;
		  j++;
		}
		}*/
	  a++;
	  if (a == 10000)
	    a = 0;
    }
  //lib->freeLib();
  //delete lib;
}

void  Session::sessionthreadElems()
{
  int i = 0;

  Command       cmd(_game_n);
  Object	*obj;
  Object	*obj2;
  std::list<Object *>::iterator it;
  std::list<Object *>::iterator it2;

  //creer la liste des objs tout les x secondes et setter leur positions
  //Mettre une liste d'obj dans la classe Session List<Object> listObj;
  //      obj = new Object(5, 46, 16, 11);
  //  static unsigned char mob_id = 10; // TO CHANGE
  std::cout << "Success for threadElems" << std::endl;


   LoadLib	*lib;
  // verification des libs
  

  while (1) // On envoie des elements à l'infini
    {
      if (i == 10000)
	i = 0; 
      //std::cout << "ID : " << (int)mob_id << std::endl;
      Create_Mob(i);
      if (i % 100 == 0)
	{
	  //Detection des collisions entre missiles joueur et mobs
	  it = _listObj.begin();
	  while (it != _listObj.end())
	    {
	      it2 = _listObj.begin();
	      while (it2 != _listObj.end())
		{
		  obj = *it;
		  obj2 = *it2;
		  if ((obj != obj2) && (obj->getType() == 5 || obj2->getType() == 5) &&
		      obj->getType() != 9 && obj2->getType() != 9 &&
		      (!(obj->getType() == 5 && obj2->getType() == 5)) &&
		      obj->getX() < obj2->getX() + 3 && obj->getX() > obj2->getX() - 3 &&
		      obj->getY() < obj2->getY() + 3 && obj->getY() > obj2->getY() - 3)
		    {
		      cmd.sendDestroy(obj->getId() , obj2->getId(), _p); 
		      _listObj.erase(it);
		      _listObj.erase(it2);
		      _score += 10;
		      cmd.sendScore(_score, _p);
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
		  obj->move(this); //Mouvement des missiles
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
			  if (obj->getType() != 9) // Les murs ne se detruisent pas
			    {
			      cmd.sendDestroy(obj->getId() , 0, _p); 
			      _listObj.erase(it);
			      it = _listObj.begin();
			    }
			  spawnPlayer(_tabPlayer[j]);
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
	      obj->move(this);
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


void	Session::spawnPlayer(Player *player)
{
  unsigned char	NewPosX;
  unsigned char	NewPosY;
  int		unblock = 10000;
  Object	*obj;
  std::list<Object *>::iterator it;

  NewPosX = 8 + rand() % 4;
  NewPosY = rand() % 32;
  it = _listObj.begin();
  while (it != _listObj.end())
    {
      obj = *it;
      if (obj->getType() != 5)
	{
	  if (obj->getX() < NewPosX + 6 && obj->getX() > NewPosX - 6 &&
	      obj->getY() < NewPosY + 6 && obj->getY() > NewPosY - 6)
	    {
	      NewPosX = 8 + rand() % 4;
	      NewPosY = rand() % 32;
	      it = _listObj.begin();
	    }
	}
      it++;
      unblock--;
      if (unblock == 0)
	return;
    }
  player->setPosx(NewPosX);
  player->setPosy(NewPosY);
}
