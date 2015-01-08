#include "Grid.h"
using namespace std;


//Constructeur de la grille de jeu board
Grid::Grid(int dim_) : dim(dim_), caseWidth(2.0 / dim_), caseHeight(2.0 / dim_)
{
	board = new Case**[dim];
	matrix = new int*[dim];
	for (int i = 0; i < dim; i++)
	{
		board[i] = new Case*[dim];
		matrix[i] = new int[dim];
	}
	int numCase = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			//* pour chaque colonne on a les mêmes valeurs de posX : caseWidth * j - 1
			//  pour chaque ligne on a les même valeurs de posY    : -caseHeight * i + (1 - caseHeight)       
			//     --> (1 - caseHeight) pour commencer à partir du haut de la fenêtre                    */
			board[i][j] = new Case(caseWidth * j - 1, -caseHeight * i + (1 - caseHeight), caseWidth, caseHeight);
			matrix[i][j] = 0;
		}
	}
	cout << "Creating Grid" << endl;
}

//Destructeur
Grid::~Grid() 
{
	for (int i = 0; i < dim; i++)
	{
		delete [] matrix[i];
	}
}

//Dessine le damier
void Grid::draw()
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			board[i][j]->draw();
		}
	}
}

//Récupération de la case cliquée
Case * Grid::getCase(float fy, float fx)
{
	int idCol = (int)((fx + 1) / caseHeight);    // récupération de l'indice de la ligne
	int idLine = (int)((fy + 1)/ caseWidth);       // récupération de l'indice de la colonne

	return board[idCol][idLine];
}

int Grid::getLine(float coordX_, float coordY_, int ww_, int wh_) {
	int wh = wh_ / 2;
	return (int)((((coordY_ - wh) / wh) + 1) / caseHeight);
}

int Grid::getCol(float coordX_, float coordY_, int ww_, int wh_) {
	int ww = ww_ / 2;
	return (int)((((coordX_ - ww) / ww) + 1) / caseWidth);
}

// renvoie la case du tableau de jeu par rapport à l'indice ligne et colonne
Case * Grid::getCase(int line, int col)
{
	assert(line < dim && col < dim);
	return board[line][col];
}
int** Grid::getMatrix()
{
	return matrix;
}
void Grid::action(int idCol, int idLine, int joueur)
{
	cout << "idLine : " << idLine << "idCol : " << idCol << endl;
	matrix[idLine][idCol] = joueur;
	board[idLine][idCol]->setType(joueur);
}
void Grid::actionIA(int x, int y, int joueur)
{
	cout << "actionIA => x : " << x << ", y : " << y << endl;
	matrix[x][y] = joueur;
	board[x][y]->setType(joueur);
}

void Grid::print()
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim * 2; j++)
		{
			if (j == dim) cout << "    ";
			if (j < dim)
			{
				cout << matrix[i][j] << " ";
			}
			else
			{
				cout << board[i][j - dim]->getType() << " ";
			}
		}
		cout << endl;
	}
}