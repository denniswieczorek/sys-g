#ifndef MONOMIAL_H
#define MONOMIAL_H


#include "Xn.h"
#include "XnList.h"

class Monomial
{
	public:
		Monomial(int=1);
		~Monomial();
		void operator+=(Xn*);	
		bool operator<(Monomial&);
		bool operator>(Monomial&);
		bool operator==(Monomial&);
		
		Monomial& operator*(Monomial*);

		//int getNumMonomials
		XnList& getVars();
		int getCoeff();
		void setCoeff(int);	
		friend std::ostream& operator<<(std::ostream&, Monomial&);

	private:
		int coeff;
		XnList vars;
};

#endif
