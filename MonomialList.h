#ifndef MONOMIAL_LIST_H
#define MONOMIAL_LIST_H

#include "Monomial.h"

class MonomialList
{
	friend std::ostream& operator<<(std::ostream&, MonomialList&);

	class Node 
	{
		friend class MonomialList;
		private: 	
			Monomial* data;
			Node* next;
	};

	public:
		MonomialList();
		~MonomialList();
		MonomialList(const MonomialList&);
		MonomialList& operator=(const MonomialList&);
		int getSize() const;
		Monomial* operator[](int);
		MonomialList& negate();
		MonomialList& operator*(Monomial*);
		//MonomialList& operator-(MonomialList*);
		MonomialList& operator+=(Monomial*);
		Monomial* getLeadingTerm();
		
	private:
		Node* head;
};

#endif
