/* 
 * File:   Grid.h
 * Purpose: Grid Class Specification
 */

#ifndef GRID_H
#define GRID_H
#include "Cell.h" //Cell Class header file

class Grid {
    int gridSize;             //Height and Width of board
    Cell **board;                   //Game board
public:
    Grid();                         //Constructor
    ~Grid();                        //Destructor
    void CreateBoard();
    void ResetBoard();
    void Update(int *);
    bool returnCellShot(int, int);
    int returnCellShip(int, int);
    void addCellShip(int, int, int);
};

#endif /* GRID_H */

