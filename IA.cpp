#include "IA.h"
using namespace std;

IA::IA()
{
	cout << "Creating AI" << endl;
}

int* IA::play(vector<vector<int>*> matrix, int dim, int j)
{
	int* res = new int[2];
	bool tmp = true;
	int x;
	int y;
	while (tmp)
	{
		x = rand() % dim;
		y = rand() % dim;
		tmp = (matrix[y]->at(x) != 0);
	}
	res[0] = x;
	res[1] = y;
	cout << "Selected by AI, x : " << x << ", y : " << y << endl;
	return res;
}