#ifndef MONOMIAL_H
#define MONOMIAL_H

#include "Xn.h"
#include "LinkedList.h"

class Monomial
{
	public:
		Monomial();
		Monomial(int);
		~Monomial();

		int getSize();	//returns the number of Xn's where Xn's may be unsimplified
		int getNumVars();	//returns the actual number of unique variables in monomial
		int getCoeff();
		LinkedList<Xn>& getMembers();
		int getDeg(); //should be pointer?
		int getDeg(int);
	    void setCoeff(int);


		void simplify();

    void operator+=(Xn*);
		void operator-=(Xn*);
		bool operator<(Monomial&);
		bool operator>(Monomial&);
		bool operator==(Monomial&);
		Monomial* operator*(Monomial*);
		Monomial* operator+(Monomial*);//these are stupid
		Monomial* operator-(Monomial*); //this too

		//Monomial& operator =(const Monomial&);	//might not be needed
		friend std::ostream& operator<<(std::ostream&, Monomial&);

	private:
		int coeff;
		LinkedList<Xn> vars;
};

#endif
