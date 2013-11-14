NAME=	do-op

RM=	rm -f

CFLAGS=	-Wall -I../include

LIB=-lmy -L../lib

CC=	gcc

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) do-op.c my_opp.c $(LIB)

all:	$(NAME) clean

clean:
	$(RM) $(NAME)

.PHONY:	$(NAME) all clean