CC=gcc
CFLAGS=-g -Wall
OBJS=main.o controller.o
TARGET=ZNS_RW

$(TARGET): $(OBJS)
			 $(CC) -o $@ $(OBJS)
main.o : controller.h main.c
controller.o: controller.h controller.c

all: $(TARGET)

clean:
		rm -f *.o
		rm -f $(TARGET)
