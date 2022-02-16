#include "BoardGame.h"

BoardGame::BoardGame()
{
    this->name = "";
    this->numPlayers = 0;
}

BoardGame::BoardGame(std::string name, int players)
{
    this->name = name;
    this->numPlayers = players;
}

std::string BoardGame::getName()
{
    return this->name;
}

void BoardGame::setName(std::string name)
{
    this->name = name;
}

int BoardGame::getNumPlayers()
{
    return this->numPlayers;
}

void BoardGame::setNumPlayers(int players)
{
    this->numPlayers = players;
}
