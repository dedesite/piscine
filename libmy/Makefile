# Makefile for MyLib

RM=	rm -f

CC=	gcc -Wall -I../include

NAME=	libmy.a

SRC= 	*.c

OBJ=	*.o

libmy: 	link

all:	link clean test fclean

build:
	$(CC) -c $(SRC)

link: build
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	mv $(NAME) ../lib/$(NAME)

clean:
	$(RM) *.o

test:	link clean
	$(CC) -o ../tests/test_libmy ../tests/test_libmy.c -lmy -L../lib
	../tests/test_libmy

fclean:	clean
	$(RM) ../lib/$(NAME)