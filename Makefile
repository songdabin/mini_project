CC = gcc
CFLAGS = -W -Wall
TARGET = product
OBJECTS = main.c myProduct.o manager.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm *.o product
