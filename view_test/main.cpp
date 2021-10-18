/*
 * Character Key
 * S = Ship
 * - = Empty
 * ! = Hit
 * * = Miss
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Grid.h"
#include "PlayerData.h"
#include "Input.h"
#include "Cell.h"
#include "Constants.h"

using namespace std;

void drawGrids(PlayerData *);
void drawSymbolKey();

int main(int argc, char** argv) {

    //////////////////////////////////////////////////////////////////////
    //                    Create Test Data                              //
    //Target Test Data
   bool tTestAry[8][8]={false,false,false,false,false,false,false,false,
                        false,true,false,false,false,false,true,false,
                        false,true,false,false,false,false,true,false,
                        false,true,false,false,false,false,true,false,
                        false,true,false,false,false,false,false,false,
                        false,false,false,true,true,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false};
  bool tShotsAry[8][8]={false,false,false,false,false,false,false,false,
                        false,true,false,false,false,false,true,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,true,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        true,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,true,false,false,false};
    bool tHitsAry[8][8]={false,false,false,false,false,false,false,false,
                        false,true,false,false,false,false,true,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false};
   

    //Player Test Data
    bool pTestAry[8][8]={false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,true,false,false,false,
                        false,false,false,false,true,false,false,false,
                        false,false,false,false,true,false,false,false,
                        false,false,false,false,true,false,false,false,
                        true,true,false,false,false,false,false,false};
    bool pShotsAry[8][8]={false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,true,
                        false,false,false,false,true,false,false,false,
                        false,true,false,false,true,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,true,
                        false,false,false,false,false,false,false,false};
    bool pHitsAry[8][8]={false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,true,false,false,false,
                        false,false,false,false,true,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false,
                        false,false,false,false,false,false,false,false};


    //Fill PlayerData with test inputs
    PlayerData *playerData;
    playerData = new PlayerData();
    //Fill player name with test Data
    playerData->setPlayerName("Lindsay");
    
    //Fill Grid with test Data
    for (int i=0; i<BOARD_WIDTH; i++){
      for(int j=0; j<BOARD_HEIGHT; j++){
        playerData->targetBoard.SetCell(i, j, tTestAry[i][j], tShotsAry[i][j], tHitsAry[i][j]);
        playerData->playerBoard.SetCell(i, j, pTestAry[i][j], pShotsAry[i][j], pHitsAry[i][j]);
      }
    }

    //*****************************************************************//
    //                            EXECUTION                            //
    //Display Symbol Key
    drawSymbolKey();
    //Use Your Function to Draw the Board
    drawGrids(playerData);
    //Make sure to Destroy Classes that Include this function
    playerData->Destroy();
   
    
    return 0;
}


void drawGrids(PlayerData *playerdata){
    //Draw current player's Grid
    cout<<playerdata->getPlayerName()<<"'s Display:"<<endl;              
    cout<<"     X   1   2   3   4   5   6   7   8"<<endl;
    cout<<"   Y +-----------------------------------+"<<endl;
    for(int row=0; row<BOARD_HEIGHT; row++){              
        cout<<"   "<<static_cast<char>('A' + row)<<" |   ";
        for(int col=0; col<BOARD_WIDTH; col++){
          char cellsymbol; //Hold the symbol to print
          //Create a pointer to the cell at targetBoard(col,row)
          Cell *cell = &playerdata->playerBoard.GetCell(col,row);
          if(cell->HasBeenShot()){ //If the cell has been shot
              if(cell->HasShip()){//If the cell has a ship
                  cellsymbol=Hit;          
              }
              else{//If the cell doesn't have a ship
                  cellsymbol=Miss;          
              }
          }
          else{//If the cell hasn't been shot
              if(cell->HasShip()){//If the cell has a ship
                  cellsymbol=Ship;          
              }
              else{//If the cell doesn't have a ship
                  cellsymbol=Empty;           
              }
          }
          cout<< cellsymbol <<"   ";
        }
        cout<<"|"<<endl;
        if(row == BOARD_WIDTH - 1){
            cout<<"     +-----------------------------------+"<<endl;
        }
    }
    
    //Draw target's grid
    cout<<"\nTarget Display:"<<endl;                 
    cout<<"     X   1   2   3   4   5   6   7   8"<<endl;
    cout<<"   Y +-----------------------------------+"<<endl;
    for(int row=0; row<BOARD_HEIGHT; row++){              
        cout<<"   "<<static_cast<char>('A' + row)<<" |   ";
        for(int col=0; col<BOARD_WIDTH; col++){
          char cellsymbol; //Hold the symbol to print
          //Create a pointer to the cell at targetBoard(col,row)
          Cell *cell = &playerdata->targetBoard.GetCell(col,row);
          if(cell->HasBeenShot()){ //If the cell has been shot
              if(cell->HasShip()){//If the cell has a ship
                  cellsymbol=Hit;          
              }
              else{//If the cell doesn't have a ship
                  cellsymbol=Miss;          
              }
          }
          else{//If the cell hasn't been shot              
                  cellsymbol=Empty;           
          }
          cout<< cellsymbol <<"   ";
        }
        cout<<"|"<<endl;
        if(row == BOARD_WIDTH - 1){
            cout<<"     +-----------------------------------+"<<endl;
        }
    }
}

void drawSymbolKey(){
    for(int i=0; i<27; i++) cout<<"*";
    cout<<endl;
    cout<<"*"<<"\tSymbol Key:"<<right<<setw(8)<<"*"<<endl;
    cout<<"*"<<right<<setw(10)<<"Empty: "<<static_cast<char>(Empty)
        <<right<<setw(10)<<"Hit: "<<static_cast<char>(Hit)<<setw(4)<<"*"<<"\n"
        <<left<<"*"<<right<<setw(10)<<"Ship: "<<static_cast<char>(Ship)
        <<right<<setw(10)<<"Miss: "<<static_cast<char>(Miss)<<setw(4)<<"*"<<endl;
    for(int i=0; i<27; i++) cout<<"*";
    cout<<endl;
}

