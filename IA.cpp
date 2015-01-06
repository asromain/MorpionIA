#include "IA.h"
using namespace std;

IA::IA()
{
	cout << "Creating AI" << endl;
}

int* IA::play(int** matrix, int dim, int *j)
{
	int* res = new int[2];
	int x;
	int y;
	do
	{
		x = rand() % dim;
		y = rand() % dim;
	} while (matrix[x][y] != 0);
	res[0] = x;
	res[1] = y;
	cout << "Selected by AI, x : " << x << ", y : " << y << endl;
	return res;
}