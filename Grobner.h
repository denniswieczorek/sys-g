#ifndef GROBNER_H
#define GROBNER_H

#include "LinkedList.h"
#include "Ideal.h"
#include "helper.h"


class Grobner
{
	friend std::ostream& operator<<(std::ostream&, Grobner&);
	public:
		Grobner();
		Grobner(Ideal);
		void initGrobnerBasis(Ideal);
		Polynomial* computeResolvent(Polynomial&, Polynomial&);
	private:
		Ideal G;
		//LinkedList<Monomial> leadingTerms;
};

#endif
