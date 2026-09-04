CC = gcc
CFLAGS = -Wall -Wextra -I./include -g
SRC = src/main.c src/bmpReader.c src/stegano.c src/utilitaire.c src/stb.c src/png_stegano.c
OBJ = $(SRC:.c=.o)
TARGET = stegano

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all
