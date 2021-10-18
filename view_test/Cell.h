
#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell(){
        ship=false;
        shot=false;
        hit=false;
    };
    void SetCell(bool hasShip){
        ship=hasShip;
    }
    void SetCell(bool hasShip,bool beenShot,bool hasHit){
        ship=hasShip;
        shot=beenShot;
        hit=hasHit;
    }

    bool HasShip(){
        return ship;
    }
    bool HasBeenShot(){
        return shot;
    }
    bool HasHit(){
        return hit;
    }

    bool Shoot(){
        shot = true;
        if(ship)
            hit = true;
        return hit;
    }

private:
    bool ship;
    bool shot;
    bool hit;
};


#endif /* CELL_H */

