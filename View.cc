#include <iostream>
#include <sstream>

#include <iomanip>


#include "View.h"



void View::mainMenu(int& choice) {
	std::string str;

	choice = -1;

	std::cout << "\n\n" ;
	std::cout << "Main Menu\n\n";
	std::cout << "1.View Ideal\n";
	std::cout << "2.View Grobner Basis\n";
	std::cout << "3.Simplify \n";
	std::cout << "4.Test \n";
	std::cout << "0.Exit\n\n";

	while (!(choice >= 0 && choice <= 4)){
		std::cout << "Enter your selection: ";
		choice = readInt();
	}
	if(choice == 0) { std::cout << std::endl; }
}

void View::displayInvalid() { std::cout << "Invalid Choice." << std::endl; }


void View::printIdeal(Ideal& J) const {
	std::cout << std::endl << J << std::endl;
}

void View::printGrobner(Grobner& G) const {
		std::cout << std::endl << G << std::endl;
}


void View::pause() const {
	std::string str;

	std::cout << "Press enter to continue...";
	getline(std::cin, str);
}


int View::readInt() const {
	std::string str;
	int num;

	std::getline(std::cin,str);
	std::stringstream ss(str);
	ss >> num;

	return num;
}
