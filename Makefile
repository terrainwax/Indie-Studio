ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

SRC		=	Src/

SRCS		=			\
			$(SRC)Main.cpp	\
			$(SRC)Clock.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	indie

CPPFLAGS	+= 	-Wall
CPPFLAGS	+= 	-Wextra
CPPFLAGS	+= 	-std=c++11
CPPFLAGS	+= 	-IInclude/

CC		=	g++

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

debug:
			$(CC) -g $(CPPFLAGS) $(SRCS) $(SRC_MA) -o $(NAME)

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
