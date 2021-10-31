/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerData.h
 * Author: jyroj
 *
 * Created on October 26, 2021, 11:56 AM
 */

#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include "Grid.h"

class PlayerData {
private:
    Grid *gridData;   
    char *playerName;
    int *shipHealth;
public:
    PlayerData();
    ~PlayerData();
    void setPlayerName(char *);
    char *returnPlayerName();
    void resetGrid();
    Grid *returnGrid();
    void shootCoordinate(int *);
    void addShipCoords(int, int, int);
    void updateGrid(Grid *);
};


#endif /* PLAYERDATA_H */

