CXX = g++
CXXFLAGS = -std=c++20 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = board.cpp gameController.cpp player.cpp progress.cpp scoreManager.cpp tetromino.cpp tetrominoFactory.cpp renderer_sfml.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = tetris

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
	rm -f highscore.txt

rebuild: clean all

play: 	
	./tetris