#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "Monomial.h"
#include "LinkedList.h"


class Polynomial
{
	public:
		Polynomial();
		~Polynomial();
		void operator+=(Monomial*);
		void operator-=(Monomial*);
		bool operator<(Polynomial&);
		bool operator>(Polynomial&);
		Polynomial* operator-(Polynomial*);
		Polynomial* operator*(Monomial*);
		Polynomial* operator+(Polynomial*);
		Monomial* getLeadingTerm();
		void simplify();		

	


		int getNumMonomials();
		LinkedList<Monomial>& getMembers();
		//bool operator==(Polynomial&);
	//	Polynomial* computeResolvent(Polynomial&, Polynomial&);
		//Polynomial* reduce(Polynomial&);
		

		friend std::ostream& operator<<(std::ostream&, Polynomial&);	
		
	private:
		LinkedList<Monomial> polynomial;


};

#endif
