CC	=	gcc

NAME	=	get_next_line

CFLAGS	=	-I../include -Wall

LDFLAGS =	-lmy -L../lib

RM	=	rm -f

SRC	=	get_next_line.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
		$(CC) -c $(SRC) $(CFLAGS)
		#$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

test:	$(NAME).o
	$(CC) -o ../tests/test_get_next_line ../tests/test_get_next_line.c $(OBJ) $(CFLAGS) $(LDFLAGS)
	../tests/test_get_next_line