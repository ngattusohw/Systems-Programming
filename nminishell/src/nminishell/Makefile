SRCDIR = ./
IDIR = ../../include/
LIBDIR = ../../lib/
LIBS = -llibmy -lliblist
CFLAGS = -I $(IDIR) -Wall -Werror --pedantic -std=c99 
CC = gcc
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

.PHONY: re fclean clean all

all: $(OBJS)
	@$(CC) $(CFLAGS) -L$(LIBDIR) $^ $(LIBS) -lncurses -o nminishell

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f nminishell

re: fclean all
