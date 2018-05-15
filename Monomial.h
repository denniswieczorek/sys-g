#ifndef MONOMIAL_H
#define MONOMIAL_H

#include "Xn.h"
#include "LinkedList.h"

class Monomial
{
	public:
		Monomial(int=1);
		~Monomial();
		void operator+=(Xn*);	
		bool operator<(Monomial&);
		bool operator>(Monomial&);
		bool operator==(Monomial&);
		//Monomial& operator =(const Monomial&);
		int getNumVars();		
		
		//Monomial& operator*(Monomial*);

		//int getNumMonomials
	
		//simplify function
		void simplify(); 
/*
NTBRW
*/



		int getDeg(LinkedList<Xn>&); //should be pointer?
		int getDeg(LinkedList<Xn>&,int);
		
		LinkedList<Xn>& getMembers();
		int getCoeff();
		void setCoeff(int);	
		friend std::ostream& operator<<(std::ostream&, Monomial&);

	private:
		int coeff;
		LinkedList<Xn> vars;
};

#endif
