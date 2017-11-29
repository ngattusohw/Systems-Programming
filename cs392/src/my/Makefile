SRCDIR = ./
IDIR = ../../include/
CFLAGS = -I$(IDIR) -Wall -Werror --pedantic -std=c99 
CC = gcc
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: lib

lib:	$(OBJS)
	ar -rc libmy.a $(OBJS)
	ranlib libmy.a
	mv libmy.a ../../lib/

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f ../../lib/libmy.a

re:     fclean all
