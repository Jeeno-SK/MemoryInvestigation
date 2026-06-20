CC      = gcc
CFLAGS  = -Wall -Wextra -O2 -Iinclude
SRC_DIR = src
OBJ_DIR = build
BIN     = memscan

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/cli.c \
       $(SRC_DIR)/parser.c \
       $(SRC_DIR)/analyzer.c \
       $(SRC_DIR)/forensics.c \
       $(SRC_DIR)/report.c \
       $(SRC_DIR)/utils.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(OBJ_DIR) $(BIN)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
