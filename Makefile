cc = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = asmgen
SRCS = main.c asmgen.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %c
	$(CC) $(CFLAGS) -c $ -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean
