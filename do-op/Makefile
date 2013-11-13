NAME=	do-op

RM=	rm -f

CC=	gcc -Wall -o

$(NAME):
	$(CC) $(NAME) do-op.c

test:
	$(CC) test test_do-op.c
	./test

all:	$(NAME) clean

clean:
	$(RM) $(NAME)