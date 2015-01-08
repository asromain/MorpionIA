#include "Minmax.h"
using namespace std;

Minmax::Minmax(int dim_, int long_win_, int jr_) : IA(dim_, long_win_, jr_) {}

Minmax::~Minmax() {}

int* Minmax::play(int** matrix, int *j_)
{
	cout << ">> PLAY: calculating minmax" << endl;
	int maxcourant = INT_MIN;
	int* res = new int[2];
	//cout << "choice between : ";
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = *j_;
				int max = calculMax(matrix, 3, autreJoueur(*j_));
				cout << "play max : " << max << "  ";
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
	cout << "res[0]=" << res[0] << ", res[1]=" << res[1] << endl;
	cout << "maxcourant choisit : " << maxcourant << endl;
	return res;
}
int Minmax::calculMin(int** matrix, int prof, int j_)
{
	cout << endl << ">>calculMin" << endl;
	int min = INT_MAX;
	int* res = eval(matrix, j_);
	int st = res[0];
	int sc = res[1];
	delete[] res;
	if (prof == 0) return (sc * prof);
	if (st != 0) return (sc * prof);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = j_;
				int tmp = calculMax(matrix, prof - 1, autreJoueur(j_));
				cout << "tmp : " << tmp << endl;
				if (tmp < min) min = tmp;
				matrix[i][j] = 0;
			}
		}
	}
	cout << "min" << min << endl;
	return min;
}
int Minmax::calculMax(int** matrix, int prof, int j_)
{
	cout << endl << ">> calculMax" << endl;
	int max = INT_MIN;
	int* res = eval(matrix, j_);
	int st = res[0];
	int sc = res[1];
	delete[] res;
	if (prof == 0) return (sc * prof);
	if (st != 0) return (sc * prof);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = j_;
				int tmp = calculMin(matrix, prof - 1, autreJoueur(j_));
				cout << "tmp : " << tmp << endl;
 				if (tmp > max) max = tmp;
				matrix[i][j] = 0;
			}
		}
	}
	cout << "max : " << max << endl;
	return max;
}

int* Minmax::eval(int** matrix, int j_)
{
	int mult = (j_ == jr) ? 1 : -1;
	int* res = evalJeu(matrix, j_);

	res[1] *= mult;

	return res;
}
int* Minmax::evalJeu(int** matrix, int j_)
{
	int longh1, longh2, longv1, longv2;
	int score, score1, score2;
	int nbh1, nbh2, nbv1, nbv2;
	int* res = new int[2];
	bool egalite = true, victoire = false;

	for (int x = 0; x < dim; x++)
	{
		for (int y = 0; y < dim; y++)
		{
			//verticale
			switch (matrix[x][y])
			{
			case 1:
				nbh1++;
				longh1++;
				if (longh2 >= long_win)
				{
					if (nbh2 == long_win)
					{
						res[0] = 1;
						res[1] = 1000;
						return res;
					}
					score2 += (longh2 * 10) + (nbh2 * 2 * 10);
				}
				nbh2 = 0;
				longh2 = 0;
				break;
			case 2:
				nbh2++;
				longh2++;
				if (longh1 >= long_win)
				{
					if (nbh1 == long_win)
					{
						res[0] = 1;
						res[1] = 1000;
						return res;
					}
					score1 += (longh1 * 10) + (nbh1 * 2 * 10);
				}
				nbh1 = 0;
				longh1 = 0;
				break;
			default:
				egalite = false;
				longh1++;
				longh2++;
				break;
			}

			//horizontale
			switch (matrix[y][x])
			{
			case 1:
				nbv1++;
				longv1++;
				if (longv2 >= long_win)
				{
					if (nbv2 == long_win)
					{
						res[0] = 1;
						res[1] = 1000;
						return res;
					}
					score2 += (longv2 * 10) + (nbv2 * 2 * 10);
				}
				nbv2 = 0;
				longv2 = 0;
				break;
			case 2:
				nbv2++;
				longv2++;
				if (longv1 >= long_win)
				{
					if (nbv1 == long_win)
					{
						res[0] = 1;
						res[1] = 1000;
						return res;
					}
					score1 += (longv1 * 10) + (nbv1 * 2 * 10);
				}
				nbv1 = 0;
				longv1 = 0;
				break;
			default:
				egalite = false;
				longv1++;
				longv2++;
				break;
			}
		}
		if (longh2 >= long_win)
		{
			if (nbh2 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				return res;
			}
			score2 += (longh2 * 10) + (nbh2 * 2 * 10);
		}
		nbh2 = 0;
		longh2 = 0;
		if (longh1 >= long_win)
		{
			if (nbh1 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				return res;
			}
			score1 += (longh1 * 10) + (nbh1 * 2 * 10);
		}
		nbh1 = 0;
		longh1 = 0;
		if (longv2 >= long_win)
		{
			if (nbv2 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				return res;
			}
			score2 += (longv2 * 10) + (nbv2 * 2 * 10);
		}
		nbv2 = 0;
		longv2 = 0;
		if (longv1 >= long_win)
		{
			if (nbv1 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				return res;
			}
			score1 += (longv1 * 10) + (nbv1 * 2 * 10);
		}
		nbv1 = 0;
		longv1 = 0;
		if (j_ == 1)
		{
			score += score1;
			score -= score2;
		}
		else
		{
			score -= score1;
			score += score2;
		}
	}
	if (egalite)
	{
		res[0] = 2;
		res[1] = 0;
		return res;
	}

	for (int x = 0; x + long_win <= dim; x++)
	{
		for (int y = 0; y < dim; y++)
		{
			if (x + y < dim)
			{
				//descendante
				switch (matrix[x + y][y])
				{
				case 1:
					nbh1++;
					longh1++;
					if (longh2 >= long_win)
					{
						if (nbh2 == long_win)
						{
							res[0] = 1;
							res[1] = 1000;
							return res;
						}
						score2 += (longh2 * 10) + (nbh2 * 2 * 10);
					}
					nbh2 = 0;
					longh2 = 0;
					break;
				case 2:
					nbh2++;
					longh2++;
					if (longh1 >= long_win)
					{
						if (nbh1 == long_win)
						{
							res[0] = 1;
							res[1] = 1000;
							return res;
						}
						score1 += (longh1 * 10) + (nbh1 * 2 * 10);
					}
					nbh1 = 0;
					longh1 = 0;
					break;
				default:
					longh1++;
					longh2++;
					break;
				}
			}

			if (x - y >= 0)
			{
				//montante
				switch (matrix[x - y][y])
				{
				case 1:
					nbv1++;
					longv1++;
					if (longv2 >= long_win)
					{
						if (nbv2 == long_win)
						{
							res[0] = 1;
							res[1] = 1000;
							return res;
						}
						score2 += (longv2 * 10) + (nbv2 * 2 * 10);
					}
					nbv2 = 0;
					longv2 = 0;
					break;
				case 2:
					nbv2++;
					longv2++;
					if (longv1 >= long_win)
					{
						if (nbv1 == long_win)
						{
							res[0] = 1;
							res[1] = 1000;
							return res;
						}
						score1 += (longv1 * 10) + (nbv1 * 2 * 10);
					}
					nbv1 = 0;
					longv1 = 0;
					break;
				default:
					longv1++;
					longv2++;
					break;
				}
			}
		}
		if (longh2 >= long_win)
		{
			if (nbh2 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				return res;
			}
			score2 += (longh2 * 10) + (nbh2 * 2 * 10);
		}
		nbh2 = 0;
		longh2 = 0;
		if (longh1 >= long_win)
		{
			if (nbh1 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				return res;
			}
			score1 += (longh1 * 10) + (nbh1 * 2 * 10);
		}
		nbh1 = 0;
		longh1 = 0;
		if (longv2 >= long_win)
		{
			if (nbv2 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				return res;
			}
			score2 += (longv2 * 10) + (nbv2 * 2 * 10);
		}
		nbv2 = 0;
		longv2 = 0;
		if (longv1 >= long_win)
		{
			if (nbv1 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				return res;
			}
			score1 += (longv1 * 10) + (nbv1 * 2 * 10);
		}
		nbv1 = 0;
		longv1 = 0;
		if (j_ == 1)
		{
			score += score1;
			score -= score2;
		}
		else
		{
			score -= score1;
			score += score2;
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
int Minmax::autreJoueur(int j_)
{
	int res = (j_ == 1) ? 2 : 1;
	return res;
}