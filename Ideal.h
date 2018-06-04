#ifndef IDEAL_H
#define IDEAL_H

#include "LinkedList.h"
#include "Polynomial.h"


class Ideal 
{
	friend std::ostream& operator<<(std::ostream&, Ideal&);
	public:
		Ideal();
		~Ideal();
		int getNumPolys();
		LinkedList<Polynomial>& getMembers();
		void operator+=(Polynomial*);
		void operator-=(Polynomial*);
		void simplify();
		Polynomial* computeResolvent(Polynomial&, Polynomial&);
					
	

	
	private:
		LinkedList<Polynomial> ideal;
};

#endif	
