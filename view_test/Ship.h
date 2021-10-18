
#ifndef SHIP_H
#define SHIP_H


class Ship {
public:
    int x;
    int y;
    int size;
    int sideways;

    Ship();

    void SetUp(int newx, int newy, int type, bool isSideways);
    bool CheckShot(int shotX, int shotY);
    bool IsDestoyed();
    
    bool IsShipOverlap(Ship b);
private:
    int hitpoints;
    //bool* hull; use dynamic array to have ship keep track of its own tiles???
    //^^ Shouldn't be needed if board checks if tile has been shot at.
    //^^Since Player wouldn't be able to shoot at the tile.
    bool destroyed;
};

#endif /* SHIP_H */

