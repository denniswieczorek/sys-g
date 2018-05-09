#include "Ideal.h"

Ideal::Ideal() {}
Ideal::~Ideal() {}

void Ideal::operator+=(Polynomial* p) { ideal+=p; }

std::ostream& operator<<(std::ostream& output, Ideal& J)
{
	output << J.ideal;
	return output;
}
