CC	=	gcc
CFLAGS	= -I../include -W -Wall
LDFLAGS = -lmy -L../lib
SRC	=	*.c
COMMON=	minitalk_common.c
OBJ 	=	$(SRC:.c=.o)
NAME	=	minitalk
TEST	=	../tests/test_minitalk

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o client $(CFLAGS) client.c $(COMMON) $(LDFLAGS)
	$(CC) -o server $(CFLAGS) server.c $(COMMON) $(LDFLAGS)


test:	$(NAME)
	$(CC) -o $(TEST) $(TEST).c $(COMMON) $(LDFLAGS) $(CFLAGS)
	$(TEST)

clean: 
	rm -f $(OBJ)
	rm -f $(TEST).o

fclean: clean
	rm -f client
	rm -f server
	rm -f $(TEST)

re: fclean all

.PHONY: all clean fclean re
