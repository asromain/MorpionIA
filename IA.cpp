#include "IA.h"
using namespace std;

IA::IA()
{
	cout << "Creating AI" << endl;
}

void IA::play(vector<vector<int>*> matrix, int dim, int* res, int j)
{
	bool tmp = true;
	int x;
	int y;
	while (tmp)
	{
		x = rand() % dim;
		y = rand() % dim;
		tmp = matrix[y]->at(x) == 0;
	}
	res[0] = x;
	res[1] = y;
}