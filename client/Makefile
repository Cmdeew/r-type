##
## Makefile for rtypr in /home/hugon_a//Desktop/Link to storage/epitech/git_rtype/rtype-2013-hugon_a/client
## 
## Made by olivier hugon
## Login   <hugon_a@epitech.net>
## 
## Started on  Tue Dec 21 14:22:45 2010 olivier hugon
## Last update Tue Dec 21 14:25:26 2010 olivier hugon
##


NAMECLT		=	client

SRCSCLT		=	AbstractMusic.cpp\
			AbstractWindow.cpp\
			Element.cpp\
			ElementFactory.cpp\
			gameclient.cpp\
			gameclientRequest.cpp\
			ImageCenter.cpp\
			udpnetwork.cpp \
			main.cpp

LIB		=	-lsfml-graphics -lsfml-system -lsfml-audio -lsfml-network -lsfml-window 

RM		=	rm -f

CC		=	g++ -o

all		:
		$(CC) $(NAMECLT) $(SRCSCLT) $(LIB)

clean		:
		$(RM) *~

fclean		: clean
		$(RM) $(NAMECLT)

re		: fclean all clean

