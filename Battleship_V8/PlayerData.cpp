/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerData.cpp
 * Author: jyroj
 * 
 * Created on October 26, 2021, 11:56 AM
 */

#include "PlayerData.h"

PlayerData::PlayerData() {
    gridData = new Grid;
    playerName = new char;
    shipHealth = new int;
}

PlayerData::~PlayerData() {

}

void PlayerData::setPlayerName(char *input) {
    playerName = input;
}

char *PlayerData::returnPlayerName() {
    return playerName;
}

void PlayerData::resetGrid() {
    gridData->ResetBoard();
}

Grid *PlayerData::returnGrid() {
    return gridData;
}

void PlayerData::shootCoordinate(int *cords) {
    gridData->Update(cords);
}

void PlayerData::updateGrid(Grid *a) {
    gridData = a;
}