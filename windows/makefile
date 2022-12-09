# paths
SRC = ./source
INCLUDE = ./include

# silent command output
MAKE += --silent

# compiler options
CXX = g++
CXXFLAGS = -Wall -Werror -g -O0 -I$(INCLUDE)

# .o and executable
EXEC = exec
OBJS = $(SRC)/map.o $(SRC)/main.o $(SRC)/entity.o $(SRC)/wnv.o $(SRC)/vampire.o $(SRC)/werewolf.o $(SRC)/avatar.o

all: run clean

$(EXEC): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

run: $(EXEC)
	@./$(EXEC)

clean:
	@del .\exec.exe
	@del .\source\*.o

.PHONY: all run clean