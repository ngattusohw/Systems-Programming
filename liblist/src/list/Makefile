SRCDIR = ./src/my/
IDIR = ./include/
CFLAGS = -I$(IDIR) -Wall -Werror --pedantic -std=c99 
CC = gcc
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: $(OBJS)

lib:	$(OBJS)
	ar -rc libtest.a $(OBJS)
	ranlib libtest.a
	mv libtest.a ./lib/

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f ./lib/libtest.a
