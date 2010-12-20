#include <iostream>
#include <vector>
#include "Factory.h"

#include "Command.h"
#include "Session.h"

int	main(int ac, char **argv)
{
	char	buffer[6];
	int		cc;
	Factory	*f;
	AbsUDPNetwork *p;
	
	f = new Factory();
	p = f->n_network();
	p->setArg(argv);
	p->CreateSocket();
	p->Bind();


	AbsThread *th;
	th = f->n_thread();
	thread  threads[4];
	int ctr = 0;


	Session *session = new Session(p, th);
	Command cmd;


	while (1)
	{

	  /*
	  buffer[0] = 0;
	  buffer[1] = 0;
	  buffer[2] = 1;
	  buffer[3] = 0;
	  buffer[4] = 0;
	  buffer[5] = 0;
	  p->Send(buffer, 6);
	  */
	  //	  p->Send("HELLO", 5);
	  cmd.receiveFromClient(session, p);



	  /*
	  cc = p->Receive(buffer);
	  std::cout << "Incoming connection..." << std::endl;
	  if ((cc == 6 && buffer[0] == 0 &&  
	       buffer[0] == 0 && buffer[1] == 0 &&
	       buffer[2] == 0 && buffer[3] == 0 &&
	       buffer[4] == 0 && buffer[5] == 0) && (ctr < 4)) // ctr = nombre de slot occupe
	    {
	      std::cout << "Incoming connection..." << std::endl;
	      session->_session_n = ctr;

	      //si session->_pingTime[0] //Faire un fonction qui fait un next et renvoie le premier _pingTime a 0
	      th->ACreateThread(&threads[ctr], NULL, (typefunc)session->sessionthreadInit, session);

	      ctr++;
	    }
	  else
	    {
	      cmd.sendNoSession(p);
	      std::cout << "Client doesn't want to connect or no session available..." << std::endl;
	    }
	  */
	  /*
	  buffer[cc] = '\0';
	  std::cout << "Message : " << buffer << std::endl;
	  p->Send("test", 4);
	  */
	}
}
