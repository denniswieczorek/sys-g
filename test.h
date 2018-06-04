#ifndef TEST_H
#define TEST_H

#include "LinkedList.h"
#include "Monomial.h"
#include "Polynomial.h"
#include "Xn.h"
#include "Ideal.h"

void Populate(Ideal& J)
{
	Xn* newX;
    Monomial* newM;
	//f = x^2 + xy^2 + y
	Polynomial* f;
	f = new Polynomial();
	//x^2	
	newM = new Monomial(1);
	newX = new Xn(1,2);
	*newM+=newX;
	*f+=newM;
	//xy^2
	newM = new Monomial(1);
	newX = new Xn(1,1);
	*newM+=newX;
	newX = new Xn(2,2);
	*newM+=newX;
	*f+=newM;
	//y
	newM = new Monomial(1);
	newX = new Xn(2,1);
	*newM+=newX;
	*f+=newM;


	//g = xy^3
	Polynomial* g;
	g = new Polynomial();
	//xy^3
	newM = new Monomial(7);
	newX = new Xn(1,1);
	*newM+=newX;
	newX = new Xn(2,3);
	*newM+=newX;
	*g+=newM;


	//h = y^5+1
	Polynomial* h;
	h = new Polynomial();
	//y^5
	newM = new Monomial(4);
	newX = new Xn(2,5);	
	*newM+=newX;
	*h+=newM;	
	//1
	newM = new Monomial(1);
	*h+=newM;

	

	J+=f;
	J+=g;
	J+=h;
}

void TestDel(Ideal& J)
{
	Polynomial * p = J.getMembers()[0];
	J-=p;		
}

//test simplify
//1+1 needs to reduce to 2 
//check if simplifying is needed before preforming operation



//test assignment
void TestAss(Ideal& J)
{
	Polynomial* p;
	p = new Polynomial();
	*p = *J.getMembers()[0];
	J+=p;
}
//test copy
void TestCopy(Ideal& J)
{
	Polynomial* p = J.getMembers()[0];
	J+=p;
}
//test - of polynomials
void TestSub(Ideal& J)
{
	Polynomial* p;
	p = *J.getMembers()[0] - J.getMembers()[0];
	J+=p;
}
//test + polynomials
void TestAdd(Ideal& J)
{
	Polynomial* p;
	p = *J.getMembers()[0] + J.getMembers()[0];
	J+=p;
}
//test * polynomials

/*
	Compute Resolvent
*/
//test get leading term
void TestLT(Ideal& J)
{
	std::cout << *J.getMembers()[2]->getLeadingTerm()  << std::endl;


}

void TestCom(Ideal& J)
{
	Polynomial*h = J.computeResolvent(*J.getMembers()[0],*J.getMembers()[1]);	
	J+=h;
}	

void TestGrobner(Ideal J, Grobner& G)
{
	G.initGrobnerBasis(J);
}

#endif	


