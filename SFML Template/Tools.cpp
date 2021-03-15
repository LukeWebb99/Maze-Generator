#include <iostream>
#include "Tools.h"

int Width()
{
	return 800;
}

int Height()
{
	return 800;
}

int Cols()
{
	return floor(Width()/Size());
}

int Rows()
{
	return floor(Height()/Size());
}

int Size()
{
	return 14;
}

int Index(int i, int j)
{
	if (i < 0 || j < 0 || i > Cols() - 1 || j > Rows() - 1) {
		return 0;
	}
	return i + j * Cols();
}
