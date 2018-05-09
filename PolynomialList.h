#ifndef POLYNOMIAL_LIST_H
#define POLYNOMIAL_LIST_H

#include "Polynomial.h"


class PolynomialList
{
	friend std::ostream& operator<<(std::ostream&,PolynomialList&);
	class Node
	{
		friend class PolynomialList;
		private:
			Polynomial* data;
			Node* next;
	};
	
	public:
		PolynomialList();
		~PolynomialList();
		PolynomialList(const PolynomialList&);
		PolynomialList& operator=(const PolynomialList&);
		int getSize() const;
		void operator+=(Polynomial*);
		//void operator-=(Polynomial*);
		Polynomial* operator[](int);
				

	private:
		Node* head;
};

#endif	
