#include <iostream>
#include <sstream>

#include <iomanip>


#include "View.h"



void View::mainMenu(int& choice) {
	std::string str;

	choice = -1;
	
	std::cout << "\n\n" ;
	std::cout << "Main Menu\n\n";
	std::cout << "1.Enter A Polynomial\n";
	std::cout << "0.Exit\n\n";
	
	while (!(choice >= 0 && choice <= 1)){
		std::cout << "Enter your selection: ";
		choice = readInt(); 
	}
	if(choice == 0) { std::cout << std::endl; }
}

void View::displayInvalid() { std::cout << "Invalid Choice." << std::endl; }

/*
void View::printXns(XnList& xl) const
{
	std::cout << std::endl << "Xn" << std::endl << std::endl << xl << std::endl;

}
*/
/*
void View::printMonomial(Monomial& mm) const
{
	std::cout << std::endl << mm << std::endl;
}
*/
/*
void View::printMonomials(MonomialList& ml) const
{
	std:: cout << std::endl << ml << std::endl;
}
*/
/*
void View::printPoly(Polynomial& p) const
{
	std::cout << std::endl << p << std::endl;
}
*/
/*
void View::printIdeal(PolynomialList& pl) const
{
	std::cout << std::endl << pl << std::endl;
}
*/
void View::printIdeal(Ideal& J) const
{
	std::cout << std::endl << J << std::endl;
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
