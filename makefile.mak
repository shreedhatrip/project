CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = billing.c item.c customer.c
OBJ = $(SRC:.c=.o)
EXEC = billing

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXEC)
