#include "Cell.h"
#include "Tools.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
Random Random::s_Instance;

void Cell::display(sf::RenderWindow & MainWindow)
{
	int x = I * Size();
	int y = J * Size();

	sf::VertexArray lines(sf::Lines, 8);
	sf::RectangleShape Rect;
	
	if (walls[0]) {
		lines[0].position = sf::Vector2f(x, y); 
	    lines[1].position = sf::Vector2f(x + Size(), y);
	}
	if (walls[1]) {
		lines[2].position = sf::Vector2f(x + Size(), y); 
	    lines[3].position = sf::Vector2f(x + Size(), y + Size());
	}
	if (walls[2]) {
		lines[4].position = sf::Vector2f(x + Size(), y + Size()); 
	    lines[5].position = sf::Vector2f(x, y + Size());
	}
	if (walls[3]) {
		lines[6].position = sf::Vector2f(x, y + Size()); 
	    lines[7].position = sf::Vector2f(x, y);
	}
	
	if (visited) {
		Rect.setOutlineThickness(0);
		Rect.setSize(sf::Vector2f(Size(), Size()));
		Rect.setFillColor(sf::Color(0, 132, 100, 100));
		Rect.setPosition(x, y); 
	}
		
	MainWindow.draw(lines);
	MainWindow.draw(Rect);

}

void Cell::update(Cell New)
{
	visited = New.visited;
}

Cell Cell::Check(std::vector<Cell>& Grid)
{
	std::vector<Cell> neighbors;
	
	Cell top    = Grid[Index(I, J - 1)];
	Cell right  = Grid[Index(I + 1, J)];
	Cell bottom = Grid[Index(I, J + 1)];
	Cell left   = Grid[Index(I - 1, J)];
	
		if (top.existes && !top.visited) {
			neighbors.push_back(top);
		}
		if (right.existes && !right.visited) {
			neighbors.push_back(right);
		}
		if (bottom.existes && !bottom.visited) {
			neighbors.push_back(bottom);
		}
		if (left.existes && !left.visited) {
			neighbors.push_back(left);
		}

		if (neighbors.size() > 0) {
			srand(time(0));
			int random = Random::Get().Int(0, neighbors.size()-1);
			int r = (rand() % neighbors.size());
		    return neighbors[random];
		}
}

void Cell::Highlight(sf::RenderWindow &MainWindow) {
	int x = I * Size();
	int y = J * Size();

	sf::RectangleShape Rect;
	Rect.setOutlineThickness(0);
	Rect.setSize(sf::Vector2f(Size(), Size()));
	Rect.setFillColor(sf::Color(255, 255, 255, 255));
	Rect.setPosition(x, y);

	MainWindow.draw(Rect);
}
