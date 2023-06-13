CC = g++
CFLAGS = -Wall

OBJFILES = test_Main.o Plant.o HornPlant.o BombPlant.o CoinPlant.o HealPlant.o Zombie.o 
TARGET = main

all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)
clean:
	rm -f $(OBJFILES) $(TARGET) *~