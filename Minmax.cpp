#include "Minmax.h"

Minmax::Minmax(int dim_) : dim(dim_), IA(dim_) {}

int* Minmax::play(int** matrix, int *j_)
{
	int maxcourant = INT_MIN;
	int* res = new int[2];
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = *j_;
				int max = calculMax(matrix, 5, j_);
				if (max > maxcourant)
				{
					maxcourant = max;
					res[0] = i;
					res[1] = j;
				}
				matrix[i][j] = 0;
			}
		}
	}
	return res;
}
int Minmax::calculMin(int** matrix, int prof, int *j_)
{
	int min = INT_MAX;
	bool pasjoue = true;

	if (prof == 0) return eval(matrix, j_);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				pasjoue = false;
				matrix[i][j] = *j_;
				int tmp = calculMax(matrix, 5, j_);
				if (tmp < min) min = tmp;
				matrix[i][j] = 0;
			}
		}
	}
	if (pasjoue) return eval(matrix, j_);
	return min;
}
int Minmax::calculMax(int** matrix, int prof, int *j_)
{
	int max = INT_MIN;
	bool pasjoue = true;

	if (prof == 0) return eval(matrix, j_);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				pasjoue = false;
				matrix[i][j] = *j_;
				int tmp = calculMin(matrix, 5, j_);
				if (tmp > max) max = tmp;
				matrix[i][j] = 0;
			}
		}
	}
	if (pasjoue) return eval(matrix, j_);
	return max;
}

int Minmax::eval(int** matrix, int *j_)
{
	
}