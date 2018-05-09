#include "Polynomial.h"

Polynomial::Polynomial() { }
Polynomial::~Polynomial() { }

void Polynomial::operator+=(Monomial* m) { polynomial+=(m); }

bool Polynomial::operator<(Polynomial& p)
{
	bool result = false;
	if(polynomial.getLeadingTerm() < p.polynomial.getLeadingTerm()){
		result = true;
	}
	return result;
}

Polynomial& Polynomial::operator-(Polynomial* p)
{
	p->polynomial.negate();
	for(int i=0; i<p->polynomial.getSize(); i++){
		polynomial+=(p->polynomial[i]);
	}	
	return *this;


}


Polynomial& Polynomial::operator*(Monomial* m) 
{
  polynomial*m;
  return *this;
}

bool Polynomial::operator>(Polynomial& p)
{
	bool result = false;
	if(polynomial.getLeadingTerm() > p.polynomial.getLeadingTerm()){
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
	output << p.polynomial;
	return output;
}