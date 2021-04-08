TARGET := list_main
CC := gcc
CFLAGS := -g -O0 -Wall

$(TARGET): main.o list.o
	$(CC) $(CFLAGS) main.o list.o -o list_main

main.o: 
	$(CC) $(CFLAGS) -c main.c

list.o:
	$(CC) $(CFLAGS) -c list.c

clean:
	$(RM) main.o list.o list_main

all:$(TARGET)
	.PHONY: all clean