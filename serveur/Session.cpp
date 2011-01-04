#include "Session.h"

Session::Session(AbsUDPNetwork *p, AbsThread *th)
{
  std::vector<Player *>     tabPlayer(4);
  _tabPlayer = tabPlayer;
  _p = p;
  _th = th;
  _pingTime[0] = 0;
  _pingTime[1] = 0;
  _pingTime[2] = 0;
  _pingTime[3] = 0;
}


Session::~Session()
{

}


void  Session::sessionthread()
{
  int cc;
  char buffer[6];
  int session = _session_n;
  Command           cmd;

  _pingTime[session] = MAX_PING_TIME;
  _tabPlayer[session] = new Player(session +1);
  std::cout << "New player assign on slot " << session << "..." << std::endl;
  cmd.sendConnect(_tabPlayer[session], _p);
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
  cmd.sendDisconnect(_tabPlayer[session], _p);
  std::cout << "Disconnecting client (player " << session + 1 << ") on slot " << session << "." << std::endl;
  std::cout << "The slot " << session << " is now free." << std::endl;
  _th->AExitThread(handles[session]);
}

void  Session::sessionthreadElems()
{
  int i = 0;
  //creer la liste des objs tout les x secondes et setter leur positions
  //Mettre une liste d'obj dans la classe Session List<Object> listObj;

  std::cout << "Success for threadElems" << std::endl;

  while (1) // On envoie des elements à l'infini
    {
      if (i == 1000)
	i = 0;

      if (i % 100 == 0)
	{

	  //Changer les positions en random sur y + ou - et - en x (pour les ennemis)
	  //Changer les positions en random sur - en x (pour les bordures)

	  std::cout << "Sending each objs position --- TEST ----" << std::endl;
	  //Faire une fonction qui parcours la liste des objets et qui envoie les positions
	  // SOURCE 0
	  // ID 5  (tout les players)
	  // CMD 3
	  // x
	  // y
	  // id_obj (unique > 4)
	  // type (5missile 11 ennemy_one)
	  //Du genre	cmd.sendObjMove(listObj, _p);
	  // PROTO cmd.sendObjMove(List<Object> *, AbsUDPNetwork *);
	}



      _th->ASleep(500);
      i++;
    }


}


void	*Session::sessionthreadElemsInit(Session *sess)
{
  sess->sessionthreadElems();
}

void	*Session::sessionthreadInit(Session *sess)
{
  sess->sessionthread();
}
