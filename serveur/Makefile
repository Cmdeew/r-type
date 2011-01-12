CC_FreeBSD	= g++

CC_linux	= g++

CC_i386-linux	= g++

CC_ia64-linux	= g++

CC_sun4		= /usr/sfw/bin/g++

CC_		= g++

NAME		= serveur

SRC		= main.cpp\
		  Command.cpp\
                  Factory.cpp\
                  Session.cpp\
                  AbsThread.cpp\
                  CUAbsThread.cpp\
                  AbsMutex.cpp\
                  CUAbsMutex.cpp\
                  AbsUDPNetwork.cpp\
                  CUAbsUDPNetwork.cpp\
                  AbsDynamicLib.cpp\
                  CUAbsDynamicLib.cpp\
		  LoadLib.cpp\
                  Player.cpp\
                  Object.cpp\
                  Game.cpp\
		  Elem.cpp


OBJ		= $(SRC:.cpp=.o)


CFLAGS		= -W -Wall -Werror -Wstrict-prototypes -pedantic

LIB		= -lpthread -ldl

RM		= rm -f


all	: $(NAME)

re	: fclean $(NAME)

$(NAME)	:	$(OBJ)
	$(CC_$(HOSTTYPE)) -o $(NAME) $(OBJ)  $(LIB)

clean	:
	$(RM) $(OBJ)
	$(RM) *~ \#*

fclean	: clean
	$(RM) $(NAME)
love	:
	@echo ". . . not war"
