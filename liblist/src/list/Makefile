SRCDIR = .
IDIR = /../../include/
LIBDIR = ../../lib/
LIBS = -lmy
CFLAGS = -I$(IDIR) -Wall -Werror --pedantic -std=c99 
CC = gcc
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

.PHONY: re fclean clean all

all: $(OBJS)
	@$(CC) $(CFLAGS) -L$(LIBDIR) $^ $(LIBS)

lib:	$(OBJS)
	ar -rc liblist.a $(OBJS)
	ranlib liblist.a
	mv liblist.a ../../lib/

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f ../../lib/liblist.a
re: clean all
