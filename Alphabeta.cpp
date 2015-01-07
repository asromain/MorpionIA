#include "Alphabeta.h"

Alphabeta::Alphabeta(int dim_) : dim(dim_), IA(dim_) {}

Alphabeta::~Alphabeta() {}

int* Alphabeta::play(int** matrix, int *j_)
{
	// 
}

int Alphabeta::calculMin(int** matrix, int prof, int *j_, int alpha, int beta)
{
	int max = INT_MIN;
	bool pasjoue = true;

	if (prof == 0) {
		return eval(matrix, j_);
	}
	else {
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				if (matrix[i][j] == 0)
				{
					// ici faut jouer le coup

					int tmp = calculMin(matrix, prof-1, j_, alpha, beta);

					// ici faut annuler le coup

					if (alpha < tmp) {
						alpha = tmp;
					}

					if (beta <= alpha) {
						return alpha;
					}
				}
			}
		}
		return alpha;
	}
}

int Alphabeta::calculMax(int** matrix, int prof, int *j_, int alpha, int beta)
{
	int max = INT_MIN;
	bool pasjoue = true;

	if (prof == 0) {
		return eval(matrix, j_);
	}
	else {
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				if (matrix[i][j] == 0)
				{
					// ici faut jouer le coup

					int tmp = calculMax(matrix, prof-1, j_, alpha, beta);

					// ici faut annuler le coup

					if (alpha < tmp) {
						alpha = tmp;
					}

					if (beta <= alpha) {
						return alpha;
					}
				}
			}
		}
		return alpha;
	}
}

int Alphabeta::eval(int** matrix, int *j_)
{
	//
}