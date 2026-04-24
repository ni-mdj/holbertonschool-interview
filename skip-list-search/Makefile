CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/search.c src/skip_list.c
OBJ = $(SRC:.c=.o)
TARGET = skip_list_search

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean