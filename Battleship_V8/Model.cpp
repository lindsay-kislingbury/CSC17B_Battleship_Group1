/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Model.cpp
 * Author: jyroj
 * 
 * Created on October 26, 2021, 12:00 PM
 */

#include "Model.h"

Model::Model(){
}

bool Model::shipFits(Grid *player, int *array, int direction, int ship){
    bool hasSpace = false;
    if (player->returnCellShip(array[0], array[1]) == 0){
        int sum = 0;
        switch(direction){
            case 1: 
                for (int i = 1; i < shipSize[ship]; i++){
                    sum = array[1] - i;
                    if(sum >= 0 && player->returnCellShip(array[0], sum) == 0){
                        hasSpace = true;
                    }     
                    else{
                        hasSpace = false;
                        return hasSpace;
                    }   
                }
                return hasSpace;
                break;
            case 2: 
                for (int i = 1; i < shipSize[ship]; i++){
                    sum = array[0] + i;
                    if(sum <= 7 && player->returnCellShip(sum, array[1]) == 0){
                        hasSpace = true;
                    }     
                    else{
                        hasSpace = false;
                        return hasSpace;
                    }   
                }
                return hasSpace;
                break;
            case 3: 
                for (int i = 1; i < shipSize[ship]; i++){
                    sum = array[1] + i;
                    if(sum <= 7 && player->returnCellShip(array[0], sum) == 0){
                        hasSpace = true;
                    }     
                    else{
                        hasSpace = false;
                        return hasSpace;
                    }   
                }
                return hasSpace;
                break;
            case 4: 
                for (int i = 1; i < shipSize[ship]; i++){
                    sum = array[0] - i;
                    if(sum >= 0 && player->returnCellShip(sum, array[1]) == 0){
                        hasSpace = true;
                    }     
                    else{
                        hasSpace = false;
                        return hasSpace;
                    }   
                }
                return hasSpace;
                break;
            default: return hasSpace; break;     
        }
    }
    else{
        return hasSpace;
    }
}

Grid *Model::placeShips(Grid *player, int *array, int direction, int ship){
    //change to 2 integers to pass
    int x = array[0];
    int y = array[1];
    int sum = 0;
    //Add ships in the direction
    switch(direction){
            case 1: 
                for (int i = 0; i < shipSize[ship]; i++){
                    sum = y - i;
                    player->addCellShip(x, sum, shipType[ship]);
                }
                break;
            case 2: 
                for (int i = 0; i < shipSize[ship]; i++){
                    sum = x + i;
                    player->addCellShip(sum, y, shipType[ship]);
                }
                break;
            case 3: 
                for (int i = 0; i < shipSize[ship]; i++){
                    sum = y + i;
                    player->addCellShip(x, sum, shipType[ship]);
                }
                break;
            case 4: 
                for (int i = 0; i < shipSize[ship]; i++){
                    sum = x - i;
                    player->addCellShip(sum, y, shipType[ship]);
                }
                break;
            default: break;
    }
    return player;
}