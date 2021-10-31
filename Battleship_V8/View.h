/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   View.h
 * Author: jyroj
 *
 * Created on October 26, 2021, 11:57 AM
 */

#ifndef VIEW_H
#define VIEW_H
#include "PlayerData.h"

class View {
public:
    void drawSymbolsKey();
    void menu();
    void rules();
    void userInputError();
    void coordinatePrompt();
    void directionPrompt();
    void playerNamePrompt(int);
    void drawPlayerGrid(PlayerData); //show only player grid. used for placement
    void shipFitMessage(bool);
    void shipPosCheckMessage();
    void quitMessage();
    void startTwoPlayerMessage();
};

#endif /* VIEW_H */

