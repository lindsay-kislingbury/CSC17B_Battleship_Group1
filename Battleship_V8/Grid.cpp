/* 
 * File:   Grid.cpp
 * Purpose: Grid Class Function Definitions
 */

#include "Grid.h"

Grid::Grid() {//Constructor
  //Set grid size
  gridSize=8;
  //Allocate dynamic array for board
  CreateBoard();
  //Sets values of board to 0
  ResetBoard();
}

Grid::~Grid(){
    //Delete allocated memory
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<gridSize; j++){
            delete board[i*j];
        }
    }
    delete board;
}

void Grid::CreateBoard() {
    board = new Cell*[gridSize];
    for (int i = 0; i < gridSize; i++) {
        board[i] = new Cell[gridSize];
    }
}

void Grid::ResetBoard(){
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            //Board uses functions to manipulate data types
            board[i][j].resetCell();
        }
    }
}

void Grid::Update(int *cords) {
    board[cords[0]][cords[1]].HasBeenShot(true);
    board[cords[0]][cords[1]].HasHit();
}

bool Grid::returnCellShot(int x, int y) {
    return board[x][y].returnShot();
}

int Grid::returnCellShip(int x, int y) {
    return board[x][y].returnShip();
}

void Grid::addCellShip(int x, int y, int ship) {
    board[x][y].HasShip(ship);
}
