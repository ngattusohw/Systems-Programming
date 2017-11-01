SRCDIR = ./
IDIR = ../../include/
LIBDIR = ../../lib/
LIBS = -lmy
CFLAGS = -I$(IDIR) -Wall -Werror --pedantic -std=c99 
CC = gcc
CSRCS = $(wildcard $(SRCDIR)/client.c)
SSRCS = $(wildcard $(SRCDIR)/server.c)
COBJS = $(CSRCS:.c=.o)
SOBJS = $(SSRCS:.c=.o)

.PHONY: re fclean clean all

all: 
	@$(CC) $(CFLAGS) client.c -o client
	@$(CC) $(CFLAGS) server.c -o server

client: $(COBJS)
	@$(CC) $(CFLAGS) -o client

server: $(SOBJS)
	@$(CC) $(CFLAGS) -o server

clean:
	rm -f $(COBJS)
	rm -f $(SOBJS)

fclean: clean
	rm -f client
	rm -f server

re: fclean all
