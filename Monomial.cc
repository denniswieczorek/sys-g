#include "Monomial.h"



Monomial::Monomial(int c)
{
	coeff = c;
	std::cout << "monoctor" << std::endl;
}

Monomial::~Monomial()
{
	std::cout<<"mono dtor" <<std::endl;
	for(int i=0;i<getNumVars();i++){
	//	delete vars[i];
	}

}

int Monomial::getNumVars() { return vars.getSize();}

void Monomial::operator+=(Xn* x) { vars+=(x); }
int  Monomial::getCoeff() { return coeff; }
LinkedList<Xn>& Monomial::getMembers() { return vars; }

/*
Monomial& Monomial::operator*(Monomial *m)
{
	std::cout<<m->vars.getSize() <<std::endl;
	for(int i=0;i<m->vars.getSize(); i++){
		vars+=(m->getVars()[i]);
	}


//	for(int i=0;i< m->vars.getSize(); i++){
	//	vars+=(m->vars[i]);

	//}

	int newCoeff = 0;
	newCoeff = coeff * m->getCoeff();
	coeff = newCoeff;
	return *this;
}


*/

int Monomial::getDeg(LinkedList<Xn>& lk)
{
	int degree = 0;
	for(int i=0; i< lk.getSize(); i++){
		degree += lk[i]->getEx();
	}
	return degree;
}
void Monomial::setCoeff(int c) { coeff = c; }

int Monomial::getDeg(LinkedList<Xn>& lk, int id) //id
{
	int degree = 0;
	for(int i=0;i<lk.getSize();i++){
		if(lk[i]->getId() == id){
			degree+= lk[i]->getEx();
		}
	}
	return degree;
}


bool Monomial::operator<(Monomial& m)	
{
	bool result = false;

	if(getDeg(vars) < getDeg(m.vars) ){
		result = true;
	}
	else if(getDeg(vars) == getDeg(m.vars) ) {
		for(int i = 0; i< vars.getSize(); i++){
			if(getDeg(vars,i) < getDeg(m.vars,i)){
				result = true;
				break;
			} 
			else if(getDeg(vars,i) > getDeg(m.vars,i)){
				result = false;
				break;
			}
			else {
				continue;
			}
		}
	}

	return result;	
}
/*

Monomial& Monomial::operator = (const Monomial& rhs)
{
	std::cout << " ass m " << std::endl;
	coeff = rhs.coeff;
	vars = rhs.vars;
}
*/

bool Monomial::operator>(Monomial& m)
{
	bool result = false;

	if(getDeg(vars) > getDeg(m.vars) ){
		result = true;
	}
	else if(getDeg(vars) ==getDeg(m.vars) ) {
		for(int i = 0; i < vars.getSize(); i++){
			if(getDeg(vars,i) > getDeg(m.vars,i)){
				result = true;
				break;
			} 
			else if(getDeg(vars,i) < getDeg(m.vars,i)){
				result = false;
				break;
			}
			else {
				continue;
			}
		}
	}

	return result;	
}

bool Monomial::operator==(Monomial& m)
{
	bool result = false;
	

	if(getDeg(vars) ==getDeg(m.vars)){
		
		if(vars.getSize() == m.vars.getSize()){

			for(int i = 0; i<vars.getSize();i++){
				if(getDeg(vars,i) == getDeg(m.vars,i)){
					std::cout<< getDeg(vars,i) << " , " << getDeg(m.vars,i) << std::endl;
					if(i == vars.getSize()-1){
						result = true;
						break;
					}
				}
			}
		}
	}
	return result;
}

/*
NTBRW
*/

void Monomial::simplify()
{

}
			

std::ostream& operator<<(std::ostream& output, Monomial& x)
{
	output << x.getCoeff() << x.vars ;
	return output;
}
