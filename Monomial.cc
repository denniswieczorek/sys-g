#include "Monomial.h"


Monomial::Monomial(int c)
{
	coeff = c;
	std::cout << "monoctor" << std::endl;
}

Monomial::~Monomial()
{
	std::cout << "mono-dtor" <<std::endl;
}

void Monomial::operator+=(Xn* x) { vars+=(x); }
int  Monomial::getCoeff() { return coeff; }
XnList& Monomial::getVars() { return vars; }
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
void Monomial::setCoeff(int c) { coeff = c; }
bool Monomial::operator<(Monomial& m)
{
	bool result = false;

	if(vars.getDeg() < m.vars.getDeg() ){
		result = true;
	}
	else if(vars.getDeg() == m.vars.getDeg() ) {
		for(int i = 0; i< vars.getSize(); i++){
			if(vars.getDeg(i) < m.vars.getDeg(i)){
				result = true;
				break;
			} 
			else if(vars.getDeg(i) > m.vars.getDeg(i)){
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

bool Monomial::operator>(Monomial& m)
{
	bool result = false;

	if(vars.getDeg() > m.vars.getDeg() ){
		result = true;
	}
	else if(vars.getDeg() == m.vars.getDeg() ) {
		for(int i = 0; i < vars.getSize(); i++){
			if(vars.getDeg(i) > m.vars.getDeg(i)){
				result = true;
				break;
			} 
			else if(vars.getDeg(i) < m.vars.getDeg(i)){
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
	

	if(vars.getDeg() == m.vars.getDeg()){
		
		if(vars.getSize() == m.vars.getSize()){

			for(int i = 0; i<vars.getSize();i++){
				if(vars.getDeg(i) == m.vars.getDeg(i)){
					std::cout<<vars.getDeg(i) << " , " << m.vars.getDeg(i) << std::endl;
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




std::ostream& operator<<(std::ostream& output, Monomial& x)
{
	output << x.getCoeff() << x.vars ;
}
