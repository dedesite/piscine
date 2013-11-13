# Makefile for MyLib

RM=	rm -f

CC=	gcc -Wall -Iinclude

NAME=	libmy.a

SRC= 	src/*.c

OBJ=	*.o

all: 	link clean

build:
	$(CC) -c $(SRC)

link: build
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	mv $(NAME) lib/$(NAME)

clean:
	$(RM) *.o

test:	link clean
	$(CC) -o tests/test_libmy tests/test_libmy.c -lmy -Llib
	tests/test_libmy

fclean:	clean
	$(RM) $(NAME)