CC = gcc
CFLAGS = -O2
TARGET = panic-nap

$(TARGET): main.c
	gcc $? $(CFLAGS) -o $(TARGET)
