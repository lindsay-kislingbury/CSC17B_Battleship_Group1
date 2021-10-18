
#ifndef PLAYERDATA_H
#define PLAYERDATA_H


#include "Grid.h"
#include "Ship.h"
#include <string>

class PlayerData {
public:
    PlayerData();
    ~PlayerData();
    void CreateFleet();
    int SetShip(int ship, int x, int y, bool sideways);
    void Destroy();
    void setPlayerName(std::string name);
    std::string getPlayerName();

    Grid targetBoard;
    Grid playerBoard;
    Ship* fleet;
    std::string playerName;

};

#endif /* PLAYERDATA_H */

