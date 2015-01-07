#include "Minmax.h"

Minmax::Minmax(int dim_, int long_win_) : IA(dim_, long_win_) {}

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
	return min * prof;
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
	return max * prof;
}

int Minmax::eval(int** matrix, int *j_)
{
	//Si le jeu est fini
	int* jf = jeuFini(matrix, j_);
	if (jf[0] != 0)
	{
		if (jf[0] == 3)
		{
			//Egalite -> on retourne 0
			return 0;
		}
		//Si l'IA a gagné, on retourne 1000 - le nombre de pions
		if (jf[0] == *j_)
		{
			return 1000;
		}
		else
		{
			//Si l'IA a perdu, on retourne -1000 + le nombre de pions
			return -1000;
		}
	}
	return jf[1];
}

int* Minmax::jeuFini(int** matrix, int* j_)
{
	bool egalite = true;
	int i, j;      // indices boucle
	int t, lg;  // dim-1, type, longueur
	int lgup, lgdown;
	int tup, tdown;
	int* res = new int[2];
	res[0] = 0;
	res[1] = 1;

	// par ligne
	for (i = 0; i < dim; i++) {
		t = matrix[i][0];
		lg = 0;
		for (j = 0; j < dim; j++) {
			if (t == matrix[i][j]) {
				lg++;
			}
			else
			{
				if (t == *j_)
				{
					res[1] += (10 + (30 * (lg - 1)));
				}
				else if (t != 0)
				{
					res[1] += (10 + (30 * (lg - 1))) * -1;
				}
				else
				{}
				t = matrix[i][j];
				lg = 1;
			}
			if (matrix[i][j] == 0)
			{
				egalite = false;
			}
			// A changer le 3 en un truc plus général !!!!
			if (lg == 3 && t != 0)
			{
				res[0] = t;
				return res;
			}
		}
	}
	if (egalite)
	{
		res[0] = t;
		return res;
	}
	//par colonnes 
	for (j = 0; j < dim; j++) {
		t = matrix[0][j];
		lg = 0;
		for (i = 0; i < dim; i++) {
			if (t == matrix[i][j]) {
				lg++;
			}
			else
			{
				if (t == *j_)
				{
					res[1] += (10 + (30 * (lg - 1)));
				}
				else if (t != 0)
				{
					res[1] += (10 + (30 * (lg - 1))) * -1;
				}
				else
				{
				}
				t = matrix[i][j];
				lg = 1;
			}
			// pareil !!!!
			if (lg == 3 && t != 0)
			{
				res[0] = t;
				return res;
			}
		}
	}

	// par diagonales
	for (j = 0; j < dim; j++)
	{
		lgup = 0;
		lgdown = 0;
		//diagonale descendante
		tup = matrix[0][j];
		tdown = matrix[dim - 1][j];
		for (int i = 0; j + i < dim; i++) {
			if (tup == matrix[j + i][i]) {
				lgup++;
			}
			else
			{
				if (tup == *j_)
				{
					res[1] += (10 + (30 * (lgup - 1)));
				}
				else if (tup != 0)
				{
					res[1] += (10 + (30 * (lgup - 1))) * -1;
				}
				else
				{
				}
				tup = matrix[j + i][i];
				lgup = 1;
			}
			if (tdown == matrix[j + i][dim - i - 1]) {
				lgdown++;
			}
			else
			{
				if (tdown == *j_)
				{
					res[1] += (10 + (30 * (lgdown - 1)));
				}
				else if (tdown != 0)
				{
					res[1] += (10 + (30 * (lgdown - 1))) * -1;
				}
				else
				{
				}
				tdown = matrix[j + i][dim - i - 1];
				lgdown = 1;
			}
			// a changer !!!
			if (lgup == 3 && tup != 0)
			{
				res[0] = tup;
				return res;
			}
			if (lgdown == 3 && tdown != 0)
			{
				res[0] = tdown;
				return res;
			}
		}
		//diagonale montante
		lgup = 0;
		lgdown = 0;
		//diagonale descendante
		tup = matrix[0][j];
		tdown = matrix[dim - 1][j];
		for (int i = 0; j - i > 0; i++) {
			if (tup == matrix[j - i][i]) {
				lgup++;
			}
			else
			{
				if (tup == *j_)
				{
					res[1] += (10 + (30 * (lgup - 1)));
				}
				else if (tup != 0)
				{
					res[1] += (10 + (30 * (lgup - 1))) * -1;
				}
				else
				{
				}
				tup = matrix[j - i][i];
				lgup = 1;
			}
			if (tdown == matrix[j - i][dim - i - 1]) {
				lgdown++;
			}
			else
			{
				if (tdown == *j_)
				{
					res[1] += (10 + (30 * (lgdown - 1)));
				}
				else if (tdown != 0)
				{
					res[1] += (10 + (30 * (lgdown - 1))) * -1;
				}
				else
				{
				}
				tdown = matrix[j - i][dim - i - 1];
				lgdown = 1;
			}
			// a changer !!!
			if (lgup == 3 && tup != 0)
			{
				res[0] = tup;
				return res;
			}
			if (lgdown == 3 && tdown != 0)
			{
				res[0] = tdown;
				return res;
			}
		}
	}
	return res;
}


int Minmax::comptePion(int** matrix)
{
	int acc = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			acc += (matrix[i][j] != 0);
		}
	}
	return acc;
}