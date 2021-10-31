/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Model.h
 * Author: jyroj
 *
 * Created on October 26, 2021, 12:00 PM
 */

#ifndef MODEL_H
#define MODEL_H
#include "PlayerData.h"

class Model{
private:
    int shipSize[5]= {5, 4, 3, 3, 2};
    int shipType[5]= {5, 4, 3, 2, 1};
public:
    Model();
    bool shipFits(Grid *, int *, int, int);
    Grid *placeShips(Grid *, int *, int, int);
};

#endif /* MODEL_H */

