#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Random.hpp"

class Cell {
public:
	Cell(int i, int j)
	{
		I = i;
		J = j;
		walls;
		visited = false;
		existes = true;
	}

	void display(sf::RenderWindow &MainWindow);
	void update(Cell New);
	Cell Check(std::vector<Cell>& Grid);
	void Highlight(sf::RenderWindow &MainWindow);

	int I;
	int J;
	bool walls[4] = {true, true, true, true};
	bool visited;
	bool existes;
};