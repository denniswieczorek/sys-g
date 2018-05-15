#include "Polynomial.h"

Polynomial::Polynomial() 
{ 
	std::cout << "poly ctor" <<std::endl;
}
Polynomial::~Polynomial() 
{
	std::cout << "poly dtor" << std::endl;	
}

int Polynomial::getNumMonomials() {return polynomial.getSize(); }

LinkedList<Monomial>& Polynomial::getMembers() { return polynomial; }

void Polynomial::operator+=(Monomial* m) { polynomial+=(m); }


Monomial* Polynomial::getLeadingTerm(LinkedList<Monomial>& m)
{
	Monomial* max = m[0];
	for(int i=0;i<m.getSize(); i++){
		if(m[i] > max){
			max = m[i];
		}
	}
	return max;
}



bool Polynomial::operator<(Polynomial& p)
{
	bool result = false;
	if(getLeadingTerm(polynomial) < getLeadingTerm(p.polynomial)){
		result = true;
	}
	return result;
}

/*
Need to redefine
Polynomial& Polynomial::operator-(Polynomial* p)
{
	p->polynomial.negate();
	for(int i=0; i<p->polynomial.getSize(); i++){
		polynomial+=(p->polynomial[i]);
	}	
	return *this;
	
  
}
*/

/*

Polynomial& Polynomial::operator*(Monomial* m) 
{
  polynomial*m;
  return *this;
}

*/

bool Polynomial::operator>(Polynomial& p)
{
	bool result = false;
	if(getLeadingTerm(polynomial) > getLeadingTerm(p.polynomial)){
		result = true;
	}
	return result;
}

/*
Polynomial* Polynomial::compueResolvent(Polynomial1& f,Polynomial2 g){

Monomial m1 = LM(F);
Monomial m2 = LM(G);

int LCM = LCM(f,g);
int difference;
Monomial f_factor = new Monomial(LCM/M2.getCoeff);
Monomial g_factor = new Monomial(LCM/M1.getCoeff);

for i=1 to max
if(deg(id=i)of f >= deg(id=i) of g)
	then difference = (deg(id=i)of f) - (deg(id= i)of g)
	Xn newXn = new Xn(i,difference);
	f_factor+=newXn;
else
	then difference = (deg(id=i)of g) - (deg(id=i)of f)
	Xn newXn = new Xn(i,difference);
	g_factor+=newXn

Polynomial rp = new Polynomial;

rp = f*f_factor - g*g_factor;
return poly;

NEED


}











*/


std::ostream& operator<<(std::ostream& output, Polynomial& p)
{
	

	for(int i=0;i<p.polynomial.getSize(); i++){
		std::ostringstream sign;
		if(p.polynomial[i]->getCoeff() <0)
			sign << "" ;// negative
		else{
			sign <<"+";	
		}
		output << sign.str()<< *p.polynomial[i];
		
	}
	return output;
}
