# Makefile for MyLib

RM=	rm -f

CC=	gcc -c -Wall -Iinclude

NAME=	libmy.a

SRC= 	src/*.c

OBJ=	*.o

all: 	link clean

build:
	$(CC) $(SRC)

link: build
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	mv $(NAME) lib/$(NAME)

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(NAME)