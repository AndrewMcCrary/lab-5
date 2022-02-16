#pragma once
#include <iostream>

class BoardGame
{
private:
	std::string name;
	int numPlayers;

public:
	BoardGame();
	BoardGame(std::string name, int players);

	std::string getName();
	void setName(std::string name);

	int getNumPlayers();
	void setNumPlayers(int players);
};

