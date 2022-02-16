#include "Shelf.h"

using namespace std;

Shelf::Shelf()
{
	this->numGames = 0;
	
}

void Shelf::add(BoardGame b)
{
	if (numGames >= SHELF_SIZE)
		throw FullShelf();
	this->games[this->numGames++] = b;
}

BoardGame Shelf::remove()
{
	if (numGames < 1)
		throw EmptyShelf();
	string name;
	cout << "Enter the name of the game you want to remove: ";
	cin >> name;
	BoardGame b = BoardGame();
	bool found = false;
	if (!numGames) {
		throw EmptyShelf();
	}

	for (int i = 0; i < (sizeof(this->games) / sizeof(BoardGame)); i++) {
		if (name == this->games[i].getName()) {
			found = true;
			b = this->games[i];
		}
		if (found && i < (sizeof(this->games) / sizeof(BoardGame) - 1))
			this->games[i] = this->games[i + 1];
	}
	if (found) {
		this->numGames--;
		return b;
	}
	throw NotFoundOnShelf();
}

int Shelf::getGamesOnShelf()
{
	return this->numGames;
}