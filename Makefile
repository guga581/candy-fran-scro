C = gcc
INC_DIR = ./include
SRC_DIR = ./src
BIN_DIR = ./bin
DST_DIR = ./dst
all: candy

candy:	$(SRC_DIR)/candy.c $(SRC_DIR)/candycrush.c
	$(CC) -o $(DST_DIR)/candy $(INC_DIR)/candy.h $(SRC_DIR)/candy.c $(SRC_DIR)/candycrush.c 

clean:
	rm -f $(DST_DIR)/*
