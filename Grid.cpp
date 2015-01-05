#include "Grid.h"
using namespace std;


//Constructeur de la grille de jeu board
Grid::Grid() : caseWidth(2.0 / DIM), caseHeight(2.0 / DIM)
{
	cout << "Creating Grid" << endl;
	int numCase = 0;
	for (int i = 0; i < DIM; i++) {
		matrix.push_back(new vector<int>);
		for (int j = 0; j < DIM; j++) {
			//* pour chaque colonne on a les m�mes valeurs de posX : caseWidth * j - 1
			//  pour chaque ligne on a les m�me valeurs de posY    : -caseHeight * i + (1 - caseHeight)       
			//     --> (1 - caseHeight) pour commencer � partir du haut de la fen�tre                    */
			board[i][j] = new Case(caseWidth * j - 1, -caseHeight * i + (1 - caseHeight), caseWidth, caseHeight);
			matrix[i]->push_back(0);
		}
	}
}

//Destructeur
Grid::~Grid() 
{

}

//Dessine le damier
void Grid::draw()
{
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			board[i][j]->draw();
		}
	}
}

//R�cup�ration de la case cliqu�e
Case * Grid::getCase(float coordX_, float coordY_, int ww_, int wh_)
{
	int ww = ww_ / 2;
	int wh = wh_ / 2;
	int idLine = (int)((((coordY_ - wh) / wh) + 1) / caseHeight);     // r�cup�ration de l'indice de la ligne
	int idCol = (int)((((coordX_ - ww) / ww) + 1) / caseWidth);       // r�cup�ration de l'indice de la colonne

	return board[idLine][idCol];
}

int Grid::getLine(float coordX_, float coordY_, int ww_, int wh_) {
	int wh = wh_ / 2;
	return (int)((((coordY_ - wh) / wh) + 1) / caseHeight);
}

int Grid::getCol(float coordX_, float coordY_, int ww_, int wh_) {
	int ww = ww_ / 2;
	return (int)((((coordX_ - ww) / ww) + 1) / caseWidth);
}

// renvoie la case du tableau de jeu par rapport � l'indice ligne et colonne
Case * Grid::getCase(int line, int col)
{
	assert(line < DIM && col < DIM);
	return board[line][col];
}
vector<vector<int>*> Grid::getMatrix()
{
	return matrix;
}
void Grid::action(int x, int y, int ww, int wh, int joueur)
{
	int w = ww / 2;
	int h = wh / 2;
	int idLine = (int)((((y - h) / h) + 1) / caseHeight);     // r�cup�ration de l'indice de la ligne
	int idCol = (int)((((x - w) / w) + 1) / caseWidth);       // r�cup�ration de l'indice de la colonne
	matrix[idLine]->at(idCol) = joueur;
	board[idLine][idCol]->setType(joueur);
}
void Grid::action(int x, int y, int joueur)
{
	matrix[x]->at(y) = joueur;
	board[x][y]->setType(joueur);
}