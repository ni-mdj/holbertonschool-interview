CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -I include
SRC = src/main.c src/search.c src/skip_list.c
OBJ = $(SRC:.c=.o)
TARGET = linear_skip

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -lm -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
