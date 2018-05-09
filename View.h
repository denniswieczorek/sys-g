#ifndef VIEW_H
#define VIEW_H

#include "Ideal.h"


class View 
{

	public:
		void mainMenu(int&);
		void pause() const;
		void displayInvalid();
	//	void printXns(XnList&) const;
	//	void printMonomial(Monomial&) const;
	//	void printMonomials(MonomialList&) const;
	//	void printPoly(Polynomial&) const;	
	//	void printIdeal(PolynomialList&) const;
		void printIdeal(Ideal&) const;
	private:
		int readInt() const;	
};
#endif

