SRCDIR = ./
IDIR = ../../include/
LIBDIR = ../../lib/
LIBS = -lmy
CFLAGS = -I $(IDIR) -L $(LIBDIR) -Wall -Werror --pedantic -std=c99 
CC = gcc
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

.PHONY: re fclean clean all

all: $(OBJS)
	@$(CC) $(CFLAGS) $^ -lmy -lncurses -o myselect

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f myselect

re: fclean all
