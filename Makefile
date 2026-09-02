CC = gcc
CFLAGS = -Wall -Wextra -I./include -g
SRC = src/main.c src/bmpReader.c
OBJ = $(SRC:.c=.o)
TARGET = stegano

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all
