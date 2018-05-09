#ifndef IDEAL_H
#define IDEAL_H

#include "PolynomialList.h"
#include "Polynomial.h"

class Ideal 
{
	friend std::ostream& operator<<(std::ostream&, Ideal&);
	public:
		Ideal();
		~Ideal();
		void operator+=(Polynomial*);
				


	
	private:
		PolynomialList ideal;
};

#endif	
