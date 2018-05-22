ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

SRC		=	Src/

SRCS		=					\
			$(SRC)Map.cpp			\
			$(SRC)Cube.cpp			\
			$(SRC)Main.cpp			\
			$(SRC)Clock.cpp			\
			$(SRC)Sphere.cpp		\
			$(SRC)ActionManager.cpp		\
			$(SRC)GraphicManager.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	indie

CPPFLAGS	+= 	-Wall
CPPFLAGS	+= 	-Wextra
CPPFLAGS	+= 	-std=c++11
CPPFLAGS	+= 	-IInclude/

LDFLAGS 	+=	-lIrrlicht
LDFLAGS 	+=	-std=c++17

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CPPFLAGS	+= -Wno-unused-private-field -I/usr/local/Cellar/irrlicht/1.8.4/include/irrlicht
	LDFLAGS		+= -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
else
	LDFLAGS 	+=	-lXxf86vm
	LDFLAGS 	+=	-lGL
	LDFLAGS 	+=	-lXext
	LDFLAGS 	+=	-lX11
	LDFLAGS 	+=	-lXcursor
endif

CC		=	g++

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

debug:
			$(CC) -g $(CPPFLAGS) $(SRCS) $(LDFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJ_MA) $(OBJ_UT)

fclean:			clean
			$(RM) $(NAME) $(NAME_UT)

re:			fclean all

.PHONY:			all clean fclean debug re

.cpp.o:
			@g++ $(CPPFLAGS) -c $< -o $@ && \
			$(ECHO) $(GREEN) "[ OK ]" $(TEAL) $< $(DEFAULT) || \
			$(ECHO) $(RED) "[ XX ]" $(TEAL) $< $(DEFAULT)
