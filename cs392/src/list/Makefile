# Makefile for liblist.a

# Begin Variables
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

IDIR = ../../include

CC = gcc
CFLAGS = -I$(IDIR) -Wall -Werror --pedantic -std=c99

LIBS = -llist -lmy
LIB_NAME = liblist.a
LIB_PATH = ../../lib
LIB_SRC = $(LIB_PATH)/$(LIB_NAME)

TEST_NAME = testlist
TEST_DIR  = ../../test
TEST_SRC  = $(TEST_DIR)/$(TEST_NAME).c
TEST_OBJ  = $(TEST_SRC:.c=.o)

RM = rm -f

# Begin Rules
.PHONY: re fclean clean all rtest test

all: $(OBJ)
	@ar -rc $(LIB_SRC) $^
	@ranlib $(LIB_SRC)

clean:
	-$(RM) $(OBJ)
	-$(RM) $(TEST_DIR)/$(TEST_OBJ)

fclean: clean
	-$(RM) $(LIB_PATH)/$(LIB_NAME)
	-$(RM) $(TEST_DIR)/$(TEST_NAME)

re: fclean all

test: $(TEST_OBJ) all
	@$(CC) $(CFLAGS) -L$(LIB_PATH) $< $(LIBS) -o $(TEST_NAME)
	@mv $(TEST_NAME) $(TEST_DIR)

rtest: re test
	@$(TEST_DIR)/$(TEST_NAME)