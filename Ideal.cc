#include "Ideal.h"

Ideal::Ideal() { std::cout << "ideal ctor" << std::endl;}
Ideal::~Ideal() { std::cout << "ideal dtor " << std::endl;}

void Ideal::operator+=(Polynomial* p) { ideal+=p; }

int Ideal::getNumPolys() { return ideal.getSize(); }

LinkedList<Polynomial>& Ideal::getMembers() { return ideal; }

std::ostream& operator<<(std::ostream& output, Ideal& J)
{
	output << "<" <<std::endl;
	for(int i=0;i<J.ideal.getSize(); i++){
		output << *J.ideal[i] <<"," <<std::endl;
	}
	output << ">";
	return output;
}
