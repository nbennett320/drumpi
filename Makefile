CXX = g++
LIBS = -lstdc++fs -lSDL2
CXXFLAGS = -g -std=c++2a -I $(INCLUDE)
BIN = bin
SOURCE = src
INCLUDE = include
OBJ = \
  DrumMachine.o \
	Step.o

LIST = $(addprefix $(BIN)/, $(OBJ))
VPATH = $(SOURCE)

ifdef opt
CXXFLAGS += -Ofast
endif

ifdef verbose
CXXFLAGS += -Wall -pedantic
endif

all: dm

dm: $(LIST) main.cpp
	$(CXX) $(CXXFLAGS) -o main $(SOURCE)/main.cpp $(LIST) $(LIBS)

$(BIN)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f main *.o bin/*
