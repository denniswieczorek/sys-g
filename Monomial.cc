#include "Monomial.h"

//Constructors
Monomial::Monomial()
{
	coeff = 0;
}
Monomial::Monomial(int c)
{
	coeff = c;
	std::cout << "            monoctor" << std::endl;
}

//Destructors
Monomial::~Monomial()
{
	std::cout<<"            mono dtor" << *this <<std::endl;
}

int Monomial::getSize() { return vars.getSize();}


//crude version
int Monomial::getNumVars() 
{
	int maxId = 1;
	for(int i=0; i<getSize(); i++){
		if(vars[i]->getId() > maxId){
			maxId = vars[i]->getId();
		}
	}
	return maxId;
}

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
		Xn* newX = new Xn(0,0);
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
	
}/*
Monomial& Monomial::operator =(const Monomial& m)
{
	std::cout <<"mono ass" << std::endl;
	coeff = m.coeff;
	vars = m.vars;

}
*/

int Monomial::getDeg()
{
	int degree = 0;
	for(int i=0; i< getSize(); i++){
		degree += vars[i]->getEx();
	}
	return degree;
}
void Monomial::setCoeff(int c) { coeff = c; }

int Monomial::getDeg(int id) 
{
	int degree = 0;
	for(int i=0;i< getSize();i++){
		if(vars[i]->getId() == id){
			degree+= vars[i]->getEx();
		}
	}
	return degree;
}


bool Monomial::operator<(Monomial& m)	
{
	bool result = false;

	if(getDeg() < m.getDeg() ){
		result = true;
	}
	else if(getDeg() == m.getDeg() ) {
		for(int i = 0; i< vars.getSize(); i++){
			if(getDeg(i) < m.getDeg(i)){
				result = true;
				break;
			} 
			else if(getDeg(i) > m.getDeg(i)){
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

	if(getDeg() > m.getDeg() ){
		result = true;
	}
	else if(getDeg() == m.getDeg() ) {
		for(int i = 0; i < vars.getSize(); i++){
			if(getDeg(i) > m.getDeg(i)){
				result = true;
				break;
			} 
			else if(getDeg(i) < m.getDeg(i)){
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
	

	if(getDeg() == m.getDeg()){
		
		if(vars.getSize() == m.vars.getSize()){

			for(int i = 0; i<vars.getSize();i++){
				if(getDeg(i) == m.getDeg(i)){
					std::cout<< getDeg(i) << " , " << m.getDeg(i) << std::endl;
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
		
	int idIndex = 0;
	

	while(vars[idIndex] != 0){
		int id = vars[idIndex]->getId();
		std::cout << id << std::endl;
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
		
		
	idIndex++;
		
		
		
	
	}

	

}
		

std::ostream& operator<<(std::ostream& output, Monomial& x)
{
	output << x.getCoeff() << x.vars ;
	return output;
}
