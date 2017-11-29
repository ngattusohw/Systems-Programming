SRCDIR = ./
IDIR = ../../include/
LIBDIR = ../../lib/
LIBS = -lmy -llist
CFLAGS = -I $(IDIR) -L$(LIBDIR) $^ $(LIBS) -Wall -Werror --pedantic -std=c99 
CC = gcc
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

.PHONY: re fclean clean all

all: $(OBJS)
	@$(CC) $(CFLAGS) -lncurses -o nminishell

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f nminishell

re: fclean all
