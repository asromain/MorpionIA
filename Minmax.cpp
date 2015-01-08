#include "Minmax.h"
using namespace std;

Minmax::Minmax(int dim_, int long_win_, int jr_) : IA(dim_, long_win_, jr_) {}

Minmax::~Minmax() {}

int* Minmax::play(int** matrix, int *j_)
{
	cout << "calculating minmax" << endl;
	int maxcourant = INT_MIN;
	int* res = new int[2];
	cout << "choice between : ";
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = *j_;
				int max = calculMax(matrix, 3, autreJoueur(*j_));
				cout << max << "  ";
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
	cout << endl;
	cout << "choisit : " << maxcourant << endl;
	return res;
}
int Minmax::calculMin(int** matrix, int prof, int j_)
{
	int min = INT_MAX;
	int* res = eval(matrix, j_);
	if (prof == 0) return (res[1] * prof);
	if (res[0] != 0) return (res[1] * prof);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = j_;
				int tmp = calculMax(matrix, prof - 1, autreJoueur(j_));
				if (tmp < min) min = tmp;
				matrix[i][j] = 0;
			}
		}
	}
	return min;
}
int Minmax::calculMax(int** matrix, int prof, int j_)
{
	int max = INT_MIN;
	int* res = eval(matrix, j_);
	if (prof == 0) return (res[1] * prof);
	if (res[0] != 0) return (res[1] * prof);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = j_;
				int tmp = calculMin(matrix, prof - 1, autreJoueur(j_));
				if (tmp > max) max = tmp;
				matrix[i][j] = 0;
			}
		}
	}
	return max;
}

int* Minmax::eval(int** matrix, int j_)
{
	bool egalite = true;
	int x, y;
	int score = 0;
	int* scoreCase = new int[2];
	int mult;

	for (x = 0; x < dim; x++)
	{
		for (y = 0; y < dim; y++)
		{
			if (matrix[x][y] == 0)
			{
				egalite = false;
				score += 10;
			}
			else
			{
				scoreCase = evalcase(matrix, x, y);
				if (scoreCase[0] == 1)
				{
					return scoreCase;
				}
				else
				{
					mult = (matrix[x][y] == j_) ? 1 : -1;
					score += (scoreCase[2] * mult);
				}
			}

		}
	}
	if (egalite)
	{
		scoreCase[0] = 2;
		scoreCase[1] = 0;
		return scoreCase;
	}
	else
	{
		scoreCase[0] = 0;
		scoreCase[1] = score;
		return scoreCase;
	}
}
int* Minmax::evalcase(int** matrix, int x, int y)
{
	int typecase = matrix[x][y];
	bool canhr = true, canhl = true, canvu = true, canvd = true, canru = true, canrd = true, canld = true, canlu = true;
	bool limr = true, liml = true, limu = true, limd = true;
	bool victh = true, victv = true, victdu = true, victdd = true;
	int* score = new int[2];
	score[0] = 0;
	score[1] = 0;
	int lh = 1, lv = 1, ldu = 1, ldd = 1;
	int adversaire = (typecase == 1) + 1;
	int i;

	for (i = 0; i < long_win; i++)
	{
		if (x + i >= dim) limr = false;
		if (x - i <= 0) liml = false;
		if (y + i >= dim) limd = false;
		if (y - i <= 0) limu = false;

		// horizontalement
		if (canhr && limr)
		{
			if (matrix[x + i][y] != adversaire)
			{
				if (matrix[x + i][y] == 0) victh = false;
				lh++;
			}
			else
			{
				victh = false;
				canhr = false;
			}
		}
		if (canhl && liml)
		{
			if (matrix[x - i][y] != adversaire)
			{
				if (matrix[x - i][y] == 0) victh = false;
				lh++;
			}
			else
			{
				victh = false;
				canhl = false;
			}
		}
		if (lh >= long_win)
		{
			score[1] += 30;
		}
		else
		{
			victh = false;
			score[1] -= 10;
		}
		

		//verticalement
		if (canvd &&  limd)
		{
			if (matrix[x][y + i] != adversaire)
			{
				if (matrix[x][y + i] == 0) victv = false;
				lv++;
			}
			else
			{
				victv = false;
				canvd = false;
			}
		}
		if (canvu && limu)
		{
			if (matrix[x][y - i] != adversaire)
			{
				if (matrix[x][y - i] == 0) victv = false;
				lv++;
			}
			else
			{
				victv = false;
				canvu = false;
			}
		}

		if (lv >= long_win)
		{
			score[1] += 30;
		}
		else
		{
			victv = false;
			score[1] -= 10;
		}

		//diagonale descendante \ 
		if (limd && limr && canrd)
		{
			if (matrix[x + i][y + i] != adversaire)
			{
				if (matrix[x + i][y + i] == 0) victdd = false;
				ldd++;
			}
			else
			{
				victdd = false;
				canrd = false;
			}
		}
		if (liml && limu && canlu)
		{
			if (matrix[x - i][y - i] != adversaire)
			{
				if (matrix[x - i][y - i] == 0) victdd = false;
				ldd++;
			}
			else
			{
				victdd = false;
				canlu = false;
			}
		}
		if (ldd >= long_win)
		{
			score[1] += 30;
		}
		else
		{
			victdd = false;
			score[1] -= 10;
		}

		//diagonale montante /
		if (limu && limr && canru)
		{
			if (matrix[x + i][y - i] != adversaire)
			{
				if (matrix[x + i][y - i] == 0) victdu = false;
				ldu++;
			}
			else
			{
				victdu = false;
				canru = false;
			}
		}
		if (liml && limd && canld)
		{
			if (matrix[x - i][y + i] != adversaire)
			{
				if (matrix[x - i][y + i] == 0) victdu = false;
				ldu++;
			}
			else
			{
				victdu = false;
				canld = false;
			}
		}
		if (ldu >= long_win)
		{
			score[1] += 30;
		}
		else
		{
			victdu = false;
			score[1] -= 10;
		}
	}

	if (victdd || victdu || victh || victv)
	{
		score[1] = 1000;
		score[0] = 1;
		return score;
	}
	else
	{
		return score;
	}
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