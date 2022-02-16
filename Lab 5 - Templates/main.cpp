#include <iostream>
#include "EntertainmentCollection.h"

using namespace std;

int main(void) {
	int buff = 0;
	EntertainmentCollection<int> collection = EntertainmentCollection<int>();
	do
	{
		std::cout << "Press 1 to add a number to the collection.\nPress 2 to remove a number from the collection.\nPress 3 to see how many numbers are currently on the collection.\nPress 4 to quit." << std::endl;
		cin >> buff;
		switch (buff) {
		case 1:
			std::cout << "Input number to add: ";
			cin >> buff;

			try {
				collection.add(buff);
				std::cout << std::endl << buff << " was added to the collection.\n" << std::endl;
			}
			catch (FullCollection e) {
				std::cout << e.what() << endl;
			}
			buff = 0;
			break;
		case 2:
			try {
				int i = collection.remove();
				cout << i << " was removed." << endl;
			}
			catch (EmptyCollection e) {
				cout << e.what() << endl;
			}
			break;
		case 3:
			cout << collection.numItemsInCollection() << " numbers in the collection." << endl;
			break;
		default:
			break;
		}

	} while (buff != 4);

	return 0;
}