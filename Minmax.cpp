#include "Minmax.h"
using namespace std;

Minmax::Minmax(int dim_, int long_win_, int jr_) : IA(dim_, long_win_, jr_) {}

Minmax::~Minmax() {}

int* Minmax::play(int** matrix, int *j_)
{
	cout << ">> PLAY: calculating minmax" << endl;
	int maxcourant = -100000;
	int* res = new int[2];
	//cout << "choice between : ";
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = *j_;
				int max = calculMin(matrix, 3, *j_);
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
	//cout << endl << ">>calculMin, porf : " << prof << endl;
	int* res = eval(matrix, j_);
	int st = res[0];
	int sc = res[1];
	//cout << "res[0]=" << st << ", res[1]=" << sc << endl;
	delete[] res;
	if (prof == 0) return (sc * prof);
	if (st != 0) return (sc * prof);

	int min = 100000;

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = autreJoueur(j_);
				int tmp = calculMax(matrix, (prof - 1), autreJoueur(j_));
				//cout << "tmp : " << tmp << endl;
				if (tmp < min) min = tmp;
				matrix[i][j] = 0;
			}
		}
	}
	//cout << "min" << min << endl;
	return min;
}
int Minmax::calculMax(int** matrix, int prof, int j_)
{
	//cout << endl << ">> calculMax, prof : " << prof << endl;
	int* res = eval(matrix, j_);
	int st = res[0];
	int sc = res[1];
	//cout << "res[0]=" << st << ", res[1]=" << sc << endl;
	delete[] res;
	if (prof == 0) return ((sc * -1) * prof);
	if (st != 0) return ((sc * -1) * prof);

	int max = -100000;

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = autreJoueur(j_);
				int tmp = calculMin(matrix, (prof - 1), autreJoueur(j_));
				//cout << "tmp : " << tmp << endl;
 				if (tmp > max) max = tmp;
				matrix[i][j] = 0;
			}
		}
	}
	//cout << "max : " << max << endl;
	return max;
}

int* Minmax::eval(int** matrix, int j_)
{
	int mult = (j_ == jr) ? 1 : -1;
	int* res = evalJeu(matrix, j_);
	//cout << "eval donne : res[0]=" << res[0] << ", res[1]=" << res[1] << endl;
	//res[1] *= mult;

	return res;
}
int* Minmax::evalJeu(int** matrix, int j_)
{
	int longh1 = 0, longh2 = 0, longv1 = 0, longv2 = 0;
	int score = 0, score1 = 0, score2 = 0;
	int nbh1 = 0, nbh2 = 0, nbv1 = 0, nbv2 = 0;
	int valv, valh;
	int* res = new int[2];
	res[0] = 0;
	res[1] = 0;
	bool egalite = true, victoire = false;

	for (int x = 0; x < dim; x++)
	{
		for (int y = 0; y < dim; y++)
		{
			//cout << "boucle v & h" << endl;
			//verticale
			valv = matrix[x][y];
			//cout << "valv : " << valv << endl;
			if (valv == 1)
			{
				nbv1++;
				longv1++;
				if (longv2 >= long_win)
				{
					if (nbv2 == long_win)
					{
						res[0] = 1;
						res[1] = 1000;
						//cout << "victoire 2" << endl;
						return res;
					}
					score2 += (longv2 * 10) + (nbv2 * 2 * 10);
				}
				nbv2 = 0;
				longv2 = 0;
			}
			if (valv == 2)
			{
				nbv2++;
				longv2++;
				if (longv1 >= long_win)
				{
					if (nbv1 == long_win)
					{
						res[0] = 1;
						res[1] = 1000;
						//cout << "victoire 1" << endl;
						return res;
					}
					score1 += (longv1 * 10) + (nbv1 * 2 * 10);
				}
				nbv1 = 0;
				longv1 = 0;
			}
			if (valv == 0)
			{
				egalite = false;
				longv1++;
				longv2++;
			}

			//horizontale
			valh = matrix[y][x];
			if (valh == 1)
			{
				nbh1++;
				longh1++;
				if (longh2 >= long_win)
				{
					if (nbh2 == long_win)
					{
						res[0] = 1;
						res[1] = 1000;
						//cout << "victoire 2" << endl;
						return res;
					}
					score2 += (longh2 * 10) + (nbh2 * 2 * 10);
				}
				nbh2 = 0;
				longh2 = 0;
			}
			if (valh == 2)
			{
				nbh2++;
				longh2++;
				if (longh1 >= long_win)
				{
					if (nbh1 == long_win)
					{
						res[0] = 1;
						res[1] = 1000;
						//cout << "victoire 1" << endl;
						return res;
					}
					score1 += (longh1 * 10) + (nbh1 * 2 * 10);
				}
				nbh1 = 0;
				longh1 = 0;
			}
			if (valh == 0)
			{
				egalite = false;
				longh1++;
				longh2++;
			}
		}
		if (longh2 >= long_win)
		{
			if (nbh2 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				//cout << "victoire 2" << endl;
				return res;
			}
			score2 += (longh2 * 10) + (nbh2 * 2 * 10);
		}
		if (longh1 >= long_win)
		{
			if (nbh1 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				//cout << "victoire 1" << endl;
				return res;
			}
			score1 += (longh1 * 10) + (nbh1 * 2 * 10);
		}
		if (longv2 >= long_win)
		{
			if (nbv2 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				//cout << "victoire 2" << endl;
				return res;
			}
			score2 += (longv2 * 10) + (nbv2 * 2 * 10);
		}
		if (longv1 >= long_win)
		{
			if (nbv1 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				//cout << "victoire 1" << endl;
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
		longh1 = 0, longh2 = 0, longv1 = 0, longv2 = 0;
		score1 = 0, score2 = 0;
		nbh1 = 0, nbh2 = 0, nbv1 = 0, nbv2 = 0;
	}
	if (egalite)
	{
		res[0] = 2;
		res[1] = 0;
		//cout << "egalite" << endl;
		return res;
	}

	for (int x = 0; x + long_win <= dim; x++)
	{
		for (int y = 0; y < dim; y++)
		{
			//cout << "boucle d" << endl;
			if (x + y < dim)
			{
				//descendante
				valh = matrix[x + y][y];
				if (valh == 1)
				{
					nbh1++;
					longh1++;
					if (longh2 >= long_win)
					{
						if (nbh2 == long_win)
						{
							res[0] = 1;
							res[1] = 1000;
							//cout << "victoire 2" << endl;
							return res;
						}
						score2 += (longh2 * 10) + (nbh2 * 2 * 10);
					}
					nbh2 = 0;
					longh2 = 0;
				}
				if (valh == 2)
				{
					nbh2++;
					longh2++;
					if (longh1 >= long_win)
					{
						if (nbh1 == long_win)
						{
							res[0] = 1;
							res[1] = 1000;
							//cout << "victoire 1" << endl;
							return res;
						}
						score1 += (longh1 * 10) + (nbh1 * 2 * 10);
					}
					nbh1 = 0;
					longh1 = 0;
				}
				if (valh == 0)
				{
					longh1++;
					longh2++;
				}
			}

			if (x - y >= 0)
			{
				//montante
				valv = matrix[x - y][y];
				if (valv == 1)
				{
					nbv1++;
					longv1++;
					if (longv2 >= long_win)
					{
						if (nbv2 == long_win)
						{
							res[0] = 1;
							res[1] = 1000;
							//cout << "victoire 2" << endl;
							return res;
						}
						score2 += (longv2 * 10) + (nbv2 * 2 * 10);
					}
					nbv2 = 0;
					longv2 = 0;
				}
				if (valv == 2)
				{
					nbv2++;
					longv2++;
					if (longv1 >= long_win)
					{
						if (nbv1 == long_win)
						{
							res[0] = 1;
							res[1] = 1000;
							//cout << "victoire 1" << endl;
							return res;
						}
						score1 += (longv1 * 10) + (nbv1 * 2 * 10);
					}
					nbv1 = 0;
					longv1 = 0;
				}
				if (valv == 0)
				{
					longv1++;
					longv2++;
				}
			}
		}
		if (longh2 >= long_win)
		{
			if (nbh2 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				//cout << "victoire 2" << endl;
				return res;
			}
			score2 += (longh2 * 10) + (nbh2 * 2 * 10);
		}
		if (longh1 >= long_win)
		{
			if (nbh1 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				//cout << "victoire 1" << endl;
				return res;
			}
			score1 += (longh1 * 10) + (nbh1 * 2 * 10);
		}
		if (longv2 >= long_win)
		{
			if (nbv2 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				//cout << "victoire 2" << endl;
				return res;
			}
			score2 += (longv2 * 10) + (nbv2 * 2 * 10);
		}
		if (longv1 >= long_win)
		{
			if (nbv1 == long_win)
			{
				res[0] = 1;
				res[1] = 1000;
				//cout << "victoire 1" << endl;
				return res;
			}
			score1 += (longv1 * 10) + (nbv1 * 2 * 10);
		}
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
		longh1 = 0, longh2 = 0, longv1 = 0, longv2 = 0;
		score1 = 0, score2 = 0;
		nbh1 = 0, nbh2 = 0, nbv1 = 0, nbv2 = 0;
	}


	//cout << "fin" << endl;
	res[1] = score;
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