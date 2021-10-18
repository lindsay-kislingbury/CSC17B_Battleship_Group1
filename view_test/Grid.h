
#ifndef GRID_H
#define GRID_H

#include "Cell.h"

class Grid {
public:
    Grid();
    ~Grid();
    Cell& GetCell(int col,int row);// X , Y Format
    
    void SetCell(int col, int row, bool hasShip, bool beenShot, bool hasHit){
      board[row][col].SetCell(hasShip, beenShot, hasHit);
    }
    
    void Destroy();
private:
    Cell** board;
    void CreateBoard();
};

#endif /* GRID_H */

