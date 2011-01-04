##
## Makefile for rtypr in /home/hugon_a//Desktop/Link to storage/epitech/git_rtype/rtype-2013-hugon_a/client
## 
## Made by olivier hugon
## Login   <hugon_a@epitech.net>
## 
## Started on  Tue Dec 21 14:22:45 2010 olivier hugon
## Last update Tue Dec 21 14:33:20 2010 olivier hugon
##


NAMECLT		=	serveur

SRCSCLT		=	Command.cpp\
			Factory.cpp\
			Session.cpp\
			AbsThread.cpp\
			CUAbsThread.cpp\
			CWAbsThread.cpp\
			AbsMutex.cpp\
			CUAbsMutex.cpp\
			main.cpp\
			AbsUDPNetwork.cpp\
			CUAbsUDPNetwork.cpp\
			CWAbsUDPNetwork.cpp\
			AbsDynamicLib.cpp\
			CUAbsDynamicLib.cpp\
			CWAbsDynamicLib.cpp\
			Player.cpp\
			Object.cpp

LIB		=	-lpthread -ldl

RM		=	rm -f

CC		=	g++ -o

all		:
		$(CC) $(NAMECLT) $(SRCSCLT) $(LIB)

clean		:
		$(RM) *~

fclean		: clean
		$(RM) $(NAMECLT)

re		: fclean all clean

