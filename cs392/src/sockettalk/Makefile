SRCDIR = ./
IDIR = ../../include/
LIBDIR = ../../lib/
LIBS = -lmy
CFLAGS = -I$(IDIR) -Wall -Werror --pedantic -std=gnu99 
CC = gcc

.PHONY: re fclean clean all

all: 
	@$(CC) $(CFLAGS) client.c -o client
	@$(CC) $(CFLAGS) new_server.c -o server

clean:
	rm -f $(COBJS)
	rm -f $(SOBJS)

fclean: clean
	rm -f client
	rm -f server

re: fclean all
