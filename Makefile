CC = gcc

LIB_FLAGS = -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

TARGET = $(BIN_DIR)/main

all: $(TARGET)

$(TARGET): main.o $(OBJ_FILES)
	$(CC) $(LIB_FLAGS) -o $@ $^

main.o: main.c
	$(CC) $(LIB_FLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(LIB_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/* main.o
