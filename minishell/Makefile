CC	=	gcc
CFLAGS	= 	-W -Wall -I../include -I.
LDFLAGS = -lmy -L../lib
SRC	=	minishell.c
OBJ 	=	$(SRC:.c=.o)
NAME	=	minishell

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
