#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
#include<iomanip>
#include"Queue.h"
#include"Factory.h"
using namespace std;
void PrintFirstMenu();
void DisplayMenu();
Factory factory;
void color(int color) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int main() {
	PrintFirstMenu();
	system("cls");
	DisplayMenu();




}




void PrintFirstMenu() {
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t         \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
	cout << "\n\n\t\t\t\t\t            Smart Factory Manufacturing\n\n";
	cout << "\t\t\t\t         \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
	cout << endl << endl << endl;
	system("pause");
	system("cls");

}
void DisplayMenu() {
	int Set[] = { 7, 7, 7, 7, 7, 7, 7, 7, 7 ,7 }; // white color
	int counter = 0;
	char key;

	while (true) {
		system("cls"); // Clear the screen for a fresh display

		cout << "\n\n\t\t\t\t\t\t   : MAIN OPTIONS MENU :\n\n\n\n\n";

		for (int i = 0; i < 10; i++) {
			gotoxy(19, 5 + i); // Move to the appropriate position to display the arrow
			if (i == counter) {
				color(12); // Display the arrow in red for the selected option
				cout << "--> ";
			}
			else {
				cout << "   "; // Display spaces for non-selected options
			}

			// Display the menu option
			if (i == 0) {
				color(Set[i]);
				cout << i + 1 << ".Add New Product ." << std::endl;
			}
			else if (i == 1) {
				color(Set[i]);
				// finished still in proccissing 
				cout << i + 1 << ".Display Factory Products ." << std::endl;
			}
			else if (i == 2) {
				color(Set[i]);
				cout << i + 1 << ".Manufacturing process ." << std::endl;
			}
			else if (i == 3) {
				color(Set[i]);
				cout << i + 1 << ".Display Finished Product ." << std::endl;
			}
			else if (i == 4) {
				color(Set[i]);
				cout << i + 1 << ".Show Statistics ." << std::endl;
			}
			else if (i == 5) {
				color(Set[i]);
				cout << i + 1 << ".   " << std::endl;
			}
			else if (i == 6) {
				color(Set[i]);
				cout << i + 1 << ".   " << std::endl;
			}
			else if (i == 7) {
				color(Set[i]);
				cout << i + 1 << ".   " << std::endl;
			}
			else if (i == 8) {
				color(Set[i]);
				cout << i + 1 << ".  " << std::endl;
			}
			else if (i == 9) {
				color(Set[i]);
				cout << i + 1 << ".  ." << std::endl;
			}
		}

		key = _getch();
		if (key == 72 && counter > 0) { // up
			Set[counter] = 7;
			counter--;
		}
		if (key == 80 && counter < 9) { // down
			Set[counter] = 7;
			counter++;
		}
		if (key == '\r') { // enter
			system("cls");
			// Call your functions here based on the selected menu option
			if (counter == 0) {
				factory.PushInSuitable();
			}
			else if (counter == 1) {
				factory.DisplayProducts();
				system("pause");
			}
			else if (counter == 2) {
				factory.ManageDeletion();
				system("pause");
			}
			else if (counter == 3) {
				factory.DisplayedFinishedProducts();
				system("pause");
			}
			else if (counter == 4) {
				factory.DisplayNumOfFinishedProducts();
				system("pause");
			}
			else if (counter == 5) {
			}
			else if (counter == 6) {
			}
			else if (counter == 7) {
			}
			else if (counter == 8) {
			}
			else if (counter == 9) {
				exit(0);
			}
			//break; // Exit the menu after an option is selected
		}
		Set[counter] = 12; // Highlight the selected option in red
	}
}
