CC = gcc

CFLAGS = -Wall -Wextra -Werror -c
TARGET = do-op
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $<
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)
re: clean all
