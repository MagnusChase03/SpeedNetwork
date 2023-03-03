CC = gcc

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

TARGET = $(BIN_DIR)/main

all: $(TARGET)

$(TARGET): main.o $(OBJ_FILES)
	$(CC) -o $@ $^

main.o: main.c
	$(CC) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/* main.o
