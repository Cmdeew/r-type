CC_FreeBSD	= g++

CC_linux	= g++

CC_ia64-linux	= g++

CC_i386-linux	= g++

CC_sun4		= /usr/sfw/bin/g++

CC_		= g++

NAME		= client

SRC		= AbstractMusic.cpp\
                  AbstractWindow.cpp\
                  MainWindow.cpp\
                  Element.cpp\
                  ElementFactory.cpp\
                  gameclient.cpp\
                  gameclientRequest.cpp\
                  ImageCenter.cpp\
                  udpnetwork.cpp \
                  main.cpp


OBJ		= $(SRC:.cpp=.o)


CFLAGS		= -W -Wall -Werror -Wstrict-prototypes -pedantic

LIB		= -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-network -lsfml-window

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
