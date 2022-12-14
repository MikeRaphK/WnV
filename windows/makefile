# paths
SRC = ./source
INCLUDE = ./include

# silent command output
MAKE += --silent

# compiler options
CXX = g++
CXXFLAGS = -Wall -Werror -g -O0 -I$(INCLUDE) -std=c++11

# .o and executable
EXEC = exec
OBJS = $(SRC)/win_map.o $(SRC)/win_main.o $(SRC)/win_entity.o $(SRC)/win_wnv.o $(SRC)/win_vampire.o $(SRC)/win_werewolf.o $(SRC)/win_avatar.o $(SRC)/win_dialogue.o 

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