CC = g++
CFLAGS = -Wall

OBJFILES = testPlantMain.o Plant.o HornPlant.o BombPlant.o CoinPlant.o
TARGET = main

all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)
clean:
	rm -f $(OBJFILES) $(TARGET) *~