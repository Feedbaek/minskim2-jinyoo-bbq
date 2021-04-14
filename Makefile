CC = gcc
CFLAGS = -Wall -Wextra -Werror

DICSRCS = srcs
HEADER = includes

SOURCES = $(DICSRCS)/main.c
TARGET = BSQ
OBJS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(TARGET)

clean:
	rm -f *.o

fclean : clean
	rm -f $(TARGET)

re: clean all
