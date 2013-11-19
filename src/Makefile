CC=g++
CFLAGS=-W -Wall -ansi -pedantic `sdl-config --cflags --libs`
LDFLAGS=

INCLUDE=`sdl-config --cflags` -I. -I./include
LIBS=`sdl-config --libs`

EXEC=main
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
