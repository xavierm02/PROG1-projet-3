CC=g++
CFLAGS=-W -Wall -ansi -pedantic `sdl-config --cflags --libs`
LDFLAGS=

INCLUDE=`sdl-config --cflags` -I. -I./include
LIBS=`sdl-config --libs`

EXEC=./main.bin
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

callgrind.out: $(EXEC)
	valgrind --tool=callgrind $(EXEC)

callgrind.svg: callgrind.out
	$(eval FILE := $(ls -l callgrind.* | head -1))
	echo $(FILE)
	./gprof2dot.py -f callgrind $(FILE) | dot -Tsvg -o output.svg

.PHONY: clean mrproper

perf: callgrind.svg

clean:
	rm -rf *.o
	rm -f callgrind.out* callgrind.svg

mrproper: clean
	rm -rf $(EXEC)
