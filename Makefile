CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

DICSRCS = srcs
HEADER = includes

SOURCES = $(DICSRCS)/main.c $(DICSRCS)/util.c ${DICSRCS}/map_handler.c ${DICSRCS}/readmap.c $(DICSRCS)/print_map.c
TARGET = BSQ
OBJS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(HEADER)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

all: $(TARGET)

clean:
	rm -f $(DICSRCS)/*.o

fclean : clean
	rm -f $(TARGET)

re: clean all
