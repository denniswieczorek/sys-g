#include "Xn.h"

Xn::Xn(int i, int e)
{
	id = i;
	exponent = e;
}

int Xn::getEx() { return exponent; }
int Xn::getId() { return id; } 
void Xn::setEx(int e) { exponent = e; }

std::ostream& operator<<(std::ostream& output, Xn& x)
{
	output << "((x." << x.id << ")^" << x.exponent << ")" ;
}

bool Xn::operator<(Xn& x)
{
	return id < x.id;
}

bool Xn::operator>(Xn& x)
{
	return id > x.id;
}

bool Xn::operator==(Xn& x)
{
	return id==x.id;
}

