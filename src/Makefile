CC=g++
CFLAGS=-W -Wall -std=c++0x `sdl-config --cflags --libs`
LDFLAGS=

INCLUDE=`sdl-config --cflags` -I. -I./include
LIBS=`sdl-config --libs`

EXEC=./main.bin
HEADERS= $(shell find . -type f -name '*.hpp')
SRC= $(shell find . -type f -name '*.cpp')
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
