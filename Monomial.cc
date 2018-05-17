#include "Monomial.h"



Monomial::Monomial(int c)
{
	coeff = c;
	std::cout << "            monoctor" << std::endl;
}

Monomial::~Monomial()
{
	std::cout<<"            mono dtor" << *this <<std::endl;
	for(int i=0;i<getNumVars();i++){
		//delete vars[i];
	}

}

int Monomial::getNumVars() { return vars.getSize();}

void Monomial::operator+=(Xn* x) { vars+=(x); }
void Monomial::operator-=(Xn* x) { vars-=(x); }
int  Monomial::getCoeff() { return coeff; }
LinkedList<Xn>& Monomial::getMembers() { return vars; }


Monomial* Monomial::operator*(Monomial *m)
{
	int newCoeff = 0;
	newCoeff = coeff * m->getCoeff();
	Monomial* resM = new Monomial(newCoeff);


	for(int i=0;i<m->vars.getSize(); i++){
		Xn* newX = new Xn(0,0);// = (m->getMembers()[i]);	
		*newX = *m->getMembers()[i];		
		
		std::cout << newX << " " << m->getMembers()[i] <<std::endl;
		*resM+=newX;    
	 }
	for(int i=0; i<vars.getSize(); i++){
		Xn* newX = new Xn(0,0);
		*newX = *getMembers()[i];
		*resM+=newX;
	}
	
	return resM;


//	for(int i=0;i< m->vars.getSize(); i++){
	//	vars+=(m->vars[i]);

	//}

	
}




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


void Monomial::simplify()
{

	std::cout << *this << std::endl;
	for(int id = 1; id< getNumVars() +1 ; id++){
		int deg = 0;
		int index = 0;
		while(this->vars[index] !=0 ){
			if(this->vars[index]->getId() == id){
				deg+=this->vars[index]->getId();
				*this-=(this->vars[index]);
				}
			else {
				index++;
			}
		}
		if(deg != 0){
			Xn* newX = new Xn(id, deg);
			*this+=newX;
		}
		
	}


	

}
		

std::ostream& operator<<(std::ostream& output, Monomial& x)
{
	output << x.getCoeff() << x.vars ;
	return output;
}
