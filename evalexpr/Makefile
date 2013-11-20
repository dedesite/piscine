CC	=	gcc
CFLAGS	= -I../include -I. -W -Wall
LDFLAGS = -lmy -L../lib
SRC	=	*.c
OBJ 	=	$(SRC:.c=.o)
NAME	=	evalexpr
TEST	=	../tests/test_$(NAME)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LDFLAGS)

test:	$(NAME)
	$(CC) -o $(TEST) $(TEST).c $(NAME).c $(NAME)_validation.c $(NAME)_npi.c $(LDFLAGS) $(CFLAGS)
	$(TEST)

clean: 
	rm -f $(OBJ)
	rm -f $(TEST).o

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

re: fclean all

.PHONY: all clean fclean re
