#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Monomial.h"
#include "MonomialList.h"

class Polynomial
{
	public:
		Polynomial();
		~Polynomial();
		void operator+=(Monomial*);
		bool operator<(Polynomial&);
		bool operator>(Polynomial&);
		Polynomial& operator-(Polynomial*);
		Polynomial& operator*(Monomial*);
		//bool operator==(Polynomial&);
		//Polynomial* computeResolvent(Polynomial&);
		//Polynomial* reduce(Polynomial&);
	

		friend std::ostream& operator<<(std::ostream&, Polynomial&);	
		
	private:
		MonomialList polynomial;


};

#endif
