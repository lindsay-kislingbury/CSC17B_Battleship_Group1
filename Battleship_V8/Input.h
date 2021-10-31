/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Input.h
 * Author: jyroj
 *
 * Created on October 26, 2021, 11:58 AM
 */

#ifndef INPUT_H
#define INPUT_H
#include "View.h"

class Input {    
private:
    int size, nameSize;
    char *input, *name;     
public:
    Input();
    ~Input();
    int *inputCoordinates();
    int inputUserSetUp(); //changed to int to chose up, down, left, right
    char *inputPlayerData(); //Input name into char array
    int inputMenu(int);
    View inputDisplay;
    char inputLikePlacement();
};

#endif /* INPUT_H */

