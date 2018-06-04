#include "Xn.h"


//Constructors
Xn::Xn()
{
		std::cout << "                Xn ctor " << std::endl;
	id		 = 0;
	exponent = 0;
}

Xn::Xn(unsigned int i, int e)
{
	std::cout << "                Xn ctor " << std::endl;
	id 		 = i;
	exponent = e;
}

//Destructor
Xn::~Xn()
{
	std::cout << "                Xn dtor" << std::endl;
}

//Simple getters and setters 

int  Xn::getEx()	  { return exponent; }
int  Xn::getId() 	  { return id; } 
void Xn::setEx(int e) { exponent = e; }


//Overloaded operators
//ordered by id, so the greatest is the lowest id (e.g. 1<3)

bool Xn::operator<(Xn& x) { return id > x.id; }
bool Xn::operator>(Xn& x) { return id < x.id; }
bool Xn::operator==(Xn& x) { return id == x.id; }

std::ostream& operator<<(std::ostream& output, Xn& x)
{
	output << "((x." << x.id << ")^" << x.exponent << ")" ;
	return output;
}
