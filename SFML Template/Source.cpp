#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tools.h"
#include "Cell.h"

using namespace std;

void UpdateGrid(vector<Cell>& Grid, Cell& Current);

void RemoveWalls(Cell Current, Cell New, vector<Cell>& Grid);

int main() {

	srand(time(0));

	std::vector<Cell> Grid;
	std::vector<Cell> Stack;

	for (int j = 0; j < Rows(); j++) {
	    for (int i = 0; i < Cols(); i++) {
			Grid.push_back(Cell(i, j));
		}
	}

	Cell Current = Grid[0];
	Grid[0].visited = true;

	sf::RenderWindow window(sf::VideoMode(Width(), Height()), "Maze");


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (int i = 0; i < Grid.size(); i++) {
			Grid[i].display(window);
		}

		Current.visited = true;
		Current.Highlight(window);
	    Grid[Grid.size()-1].Highlight(window);

		Cell Next = Current.Check(Grid);

		if (!Next.visited) {
			
			Next.visited = true;
			
			Stack.push_back(Current);
			
			RemoveWalls(Current, Next, Grid);
			
			Current = Next;

		} 
		else if (Stack.size() > 1) {
			Stack.pop_back();
		    Current = Stack[Stack.size()-1];
		}

		UpdateGrid(Grid, Current);
	
		window.display();
	
	}
}

void UpdateGrid(vector<Cell>& Grid, Cell& Current) {
	for (int i = 0; i < Grid.size(); i++) {
		if ((Grid[i].I + Grid[i].J * Cols() - 1) == (Current.I + Current.J * Cols() - 1)) {
			Grid[i].visited = true;
		}
	}
}

void RemoveWalls(Cell Current, Cell New, vector<Cell>& Grid)
{
	int x = Current.I - New.I;
	if (x == 1) {
		Grid[Index(Current.I, Current.J)].walls[3] = false;
		Grid[Index(New.I, New.J)].walls[1] = false;
	} 
	else if (x == -1) {
		Grid[Index(Current.I, Current.J)].walls[1] = false;
		Grid[Index(New.I, New.J)].walls[3] = false;
	}

	int y = Current.J - New.J;
	if (y == 1) {
		Grid[Index(Current.I, Current.J)].walls[0] = false;
		Grid[Index(New.I, New.J)].walls[2] = false;
	}
	else if (y == -1) {
		Grid[Index(Current.I, Current.J)].walls[2] = false;
		Grid[Index(New.I, New.J)].walls[0] = false;
	}
}

