#include "Minmax.h"

Minmax::Minmax() : IA() {}

int* Minmax::play(vector<vector<int>*> matrix, int dim, int *j_)
{
	int maxcourant = INT_MIN;
	int* res = new int[2];
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix.at(i)->at(j) == 0)
			{
				matrix.at(i)->at(j) = *j_;
				int max = calculMax(&matrix, 5, j_);
				if (max > maxcourant)
				{
					maxcourant = max;
					res[0] = i;
					res[1] = j;
				}
				matrix.at(i)->at(j) = 0;
			}
		}
	}
	return res;
}
int Minmax::calculMin(vector<vector<int>*>* matrix, int dim, int prof, int *j_)
{
	int min = INT_MAX;
	bool pasjoue = true;

	if (prof == 0) return eval(matrix, dim, j_);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix->at(i)->at(j) == 0)
			{
				pasjoue = false;
				matrix->at(i)->at(j) = *j_;
				int tmp = calculMax(matrix, dim, 5, j_);
				if (tmp < min) min = tmp;
				matrix->at(i)->at(j) = 0;
			}
		}
	}
	if (pasjoue) return eval(matrix, dim, j_);
	return min;
}
int Minmax::calculMax(vector<vector<int>*>* matrix, int dim, int prof, int *j_)
{
	int max = INT_MIN;
	bool pasjoue = true;

	if (prof == 0) return eval(matrix, dim, j_);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix->at(i)->at(j) == 0)
			{
				pasjoue = false;
				matrix->at(i)->at(j) = *j_;
				int tmp = calculMin(matrix, dim, 5, j_);
				if (tmp > max) max = tmp;
				matrix->at(i)->at(j) = 0;
			}
		}
	}
	if (pasjoue) return eval(matrix, dim, j_);
	return max;
}

int Minmax::eval(vector<vector<int>*>* matrix, int dim, int *j_)
{
	int score = 0;
	//ligne (à généraliser)
	bool egalite = true;
	for (int i = 0; i < dim; i++) {
		int t = matrix->at(i)->at(0);
		int lg = 0;
		for (int j = 0; j < dim; j++) {
			if (t == matrix->at(i)->at(j)) {
				lg++;
			}
			else
			{
				t = matrix->at(i)->at(j);
				lg = 1;
			}
			if (matrix->at(i)->at(j) == 0)
			{
				egalite = false;
			}
			if (lg == LONG_TO_WIN && t != 0)
			{
				setStatus(2);
				gagnant = turn + 1;
				return;
			}
		}
	}
	if (egalite)
	{
		setStatus(2);
		gagnant = 0;
		return;
	}
	//colonne (à généraliser)
	for (int j = 0; j < DIM; j++) {
		int t = gr->getCase(0, j)->getType();
		int lg = 0;
		for (int i = 0; i < DIM; i++) {
			if (t == gr->getCase(i, j)->getType()) {
				lg++;
			}
			else
			{
				t = gr->getCase(i, j)->getType();
				lg = 1;
			}
			if (lg == LONG_TO_WIN && t != 0)
			{
				setStatus(2);
				gagnant = turn + 1;
				return;
			}
		}
	}
	//diagonale (à généraliser)
}