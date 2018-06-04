#include "Polynomial.h"

Polynomial::Polynomial() 
{ 
	std::cout << "        poly ctor" <<std::endl;
}
Polynomial::~Polynomial() 
{
	std::cout << "        poly dtor" << std::endl;	
}

int Polynomial::getNumMonomials() {return polynomial.getSize(); }

LinkedList<Monomial>& Polynomial::getMembers() { return polynomial; }

void Polynomial::operator+=(Monomial* m) { polynomial+=(m); }
void Polynomial::operator-=(Monomial* m) { polynomial-=(m); }



void Polynomial::simplify()
{

	int index = 0;
	//int id = 1;
	
	
	while(polynomial[index] != 0){
		if(polynomial[index]->getCoeff() == 0){
			*this-=polynomial[index];
		}
		else{

			
			polynomial[index]->simplify();
			index++;
		}
	}
	index = 0;
	while(polynomial[index] != 0){
		int index2 = index+1;
		while(polynomial[index2] != 0){		
			std::cout << *polynomial[index] << " " << *polynomial[index2] << std::endl;	
			if(*polynomial[index] == *polynomial[index2]){
				std:: cout << "triggered" << std::endl;
				polynomial[index]->setCoeff(polynomial[index]->getCoeff() + polynomial[index2]->getCoeff());
				*this-=polynomial[index2];
			}
			else {
				index2++;
			}
		}
		index++;
	}

			

	
}


Monomial* Polynomial::getLeadingTerm()
{
	Monomial* max = polynomial[0];
	for(int i=0;i<polynomial.getSize(); i++){
		if(*polynomial[i] > *max){
			max = polynomial[i];
		}
	}
	return max;
}



bool Polynomial::operator<(Polynomial& p)
{
	bool result = false;
	if(getLeadingTerm() < p.getLeadingTerm()){
		result = true;
	}
	return result;
}


Polynomial* Polynomial::operator+(Polynomial* p)
{

	Polynomial* newP = new Polynomial();
	Monomial* newM;
	for(int i=0; i<getNumMonomials(); i++){
		newM = new Monomial(1);

		*newM = *polynomial[i];

		*newP+=newM;

	}
	for(int i=0;i<p->getNumMonomials(); i++){
				Monomial* newM = new Monomial(1);
		*newM = *p->polynomial[i];
		*newP+=newM;


	}

	return newP;
}
Polynomial* Polynomial::operator-(Polynomial* p)
{
	Polynomial* newP = new Polynomial();
	
	Monomial* newM = new Monomial(-1);
	
	p = *p*newM; // this is going to change p
	
	newP = *p + this;

	return newP;
		
	
  
}



Polynomial* Polynomial::operator*(Monomial* m) 
{
	Polynomial* resP = new Polynomial();	
  	for(int i=0; i< getNumMonomials(); i++){
		Monomial* newM =  new Monomial(m->getCoeff() ); // this might be silly
		newM = *polynomial[i] * m; //because i am just overwritting coeff
		*resP+=newM;
	}
	return resP;
	
}


bool Polynomial::operator>(Polynomial& p)
{
	bool result = false;
	if(getLeadingTerm() > p.getLeadingTerm()){
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
