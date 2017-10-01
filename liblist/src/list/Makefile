SRCDIR = .
IDIR = /../include/
CFLAGS = -I$(IDIR) -Wall -Werror --pedantic -std=c99 
CC = gcc
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: $(OBJS)

lib:	$(OBJS)
	ar -rc liblist.a $(OBJS)
	ranlib liblist.a
	mv liblist.a /../lib/

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f /../lib/liblist.a
