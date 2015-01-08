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
	int longh1, longh2, longv1, longv2;
	int score1, score2;
	int* res = new int[2];
	for (int x = 0; x < dim; x++)
	{
		for (int y = 0; y < dim; y++)
		{

			switch (matrix[x][y])
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;
			}
			switch (matrix[y][x])
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;
			}
		}
	}
	return res;
}
int* Minmax::evalcase(int** matrix, int x, int y)
{
	int* res;
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