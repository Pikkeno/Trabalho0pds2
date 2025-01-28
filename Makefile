# Variáveis
CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -Iinclude -g
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=src/%.o)
EXEC = JogosDeTabuleiro

# Regras
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q src\*.o $(EXEC) 2>nul || exit 0

debug: CFLAGS += -DDEBUG
debug: all

.PHONY: all clean debug
