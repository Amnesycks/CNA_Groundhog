##
## EPITECH PROJECT, 2020
## CNA
## File description:
## Makefile
##

CC	=	g++

RM	=	rm -f

MAIN	=	src/main.cpp

OBJ_MAIN=	$(MAIN:.cpp=.o)

SRCS    =	src/Groundhog.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	groundhog

CPPFLAGS        = -I ./include

CPPFLAGS        += -Wall -Wextra -pedantic -g3

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJ_MAIN)
		$(CC) $(OBJS) $(OBJ_MAIN) -o $(NAME)
clean:
		$(RM) $(OBJS) *.g*

fclean:		clean
		$(RM) $(NAME)
		$(RM) *.gc*
		$(RM) unit_tests
		$(RM) *.o

tests_run:
		$(CC) --coverage $(CPPFLAGS) $(SRCS) $(LIBSRC) -c
		$(CC) $(CPPFLAGS) $(TEST) -c
		g++ -o unit_tests *.o -lcriterion -lgcov
		./unit_tests
		gcovr
		gcovr -b

re:				fclean all

sweet:			all clean

.PHONY: all clean fclean re
