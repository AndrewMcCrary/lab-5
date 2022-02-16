#pragma once
#include "BoardGame.h"

#define SHELF_SIZE 2

class Shelf
{
private:	
	BoardGame games[SHELF_SIZE];
	int numGames = 0;

public:
	Shelf();
	void add(BoardGame b);
	BoardGame remove();
	int getGamesOnShelf();
};

struct FullShelf : std::exception {
	const char* what() const throw ()
	{
		return "The shelf is full.";
	}
};

struct EmptyShelf : std::exception {
	const char* what() const throw ()
	{
		return "The shelf is empty.";
	}
};

struct NotFoundOnShelf : std::exception {
	const char* what() const throw ()
	{
		return "The game is not on the shelf.";
	}
};