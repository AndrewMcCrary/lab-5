#include <iostream>
#include <string>
#include "Shelf.h"
#include "BoardGame.h"

using namespace std;

int main(void) {
	bool cont = true;
	int input;

	Shelf shelf1 = Shelf();
	while (cont){
		std::cout << "Press 1 to add a board game to the shelf.\nPress 2 to remove a board game from the shelf.\nPress 3 to see how many board games are currently on the shelf.\nPress 4 to quit." << std::endl;
		std::cin >> input;

		string name = "";
		int players = 0;
		BoardGame* b = nullptr;
		BoardGame buff;

		switch(input){
		case 1:
			std::cout << "Input name of game and number of players (press enter after each value): ";
			cin >> name;
			cin >> players;
			b = new BoardGame(name, players);

			try {
				shelf1.add(*b);
				std::cout << std::endl << name << " was added to the shelf.\n" << std::endl;
			}
			catch (FullShelf e) {
				std::cout << e.what() << endl;
			}
			break;
		case 2:
			try {
				buff = shelf1.remove();
				std::cout << endl << buff.getName() << " was removed from the shelf." << std::endl << endl;
			}
			catch (EmptyShelf e) {
				cout << e.what() << endl;
			}
			catch (NotFoundOnShelf e) {
				cout << e.what() << endl;
			}
			break;
		case 3:
			std::cout << endl << "There are " << shelf1.getGamesOnShelf() << " games on the shelf" << std::endl << endl;
			break;
		case 4:
			cont = false;
			break;
		}
	}

	return 0;
}
