CC = g++

STD = -std=c++0x

CFLAGS = -g -Wall 
 
SRC = $(wildcard *.cpp)

OBJ = $(patsubst %cpp, %o, $(SRC))

BIN = company
 
all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN)

%.o:%.cpp
	$(CC) $(STD) $(CFLAGS) -c $< -o $@

clean:
	rm  $(BIN) $(OBJ)
