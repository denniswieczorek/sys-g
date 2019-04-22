#include "Polynomial.h"

/********************
STATIC VARIABLE
********************/
int Polynomial::id_incrementer = 1;
/********************
CONSTRUCTOR
********************/
Polynomial::Polynomial() {
  leading_term = 0; //TODO this needs to be global
  poly_id = id_incrementer;
  id_incrementer++;
}

Polynomial::Polynomial(std::string str){
  std::vector<std::string> ts;
  std::string curr = "";
  leading_term = 0;
  poly_id = id_incrementer;
  id_incrementer++;



  for(unsigned int index = 0; index < str.size() ; index++){
    if(str[index] == '+' || str[index]=='-'){
      ts.push_back(curr);
      curr = str[index];
    }
    else {
      curr = curr + str[index];
    }
  }

  ts.push_back(curr);
  for(unsigned int i=0; i<ts.size() ;i++){
    if(ts[i] != ""){
        Term t = Term(ts[i]);
      *this = *this + t;

  }}
}

/********************
ACCESS
********************/
int Polynomial::get_poly_id() const { return poly_id;}
int Polynomial::number_of_terms() const { return polynomial.size(); }
int Polynomial::get_degree() const {
  int deg = 0;
  for(int i=0; i<number_of_terms(); i++){
    if(polynomial[i].get_degree() > deg){
      deg = polynomial[i].get_degree();
    }
  }
  return deg;
}

Term& Polynomial::get_leading_term()  { return leading_term; }

const std::vector<Term>& Polynomial::members() const { return polynomial; }
Term& Polynomial::operator[](unsigned int i)  { return polynomial[i]; }





/********************
MODIFIERS
********************/
Polynomial Polynomial::operator+(Term& t){
  if(t > leading_term){
    leading_term = t;
  }
  Polynomial tempP = *this;
  tempP.polynomial.push_back(t);
  return tempP;
}

Polynomial Polynomial::operator+(Polynomial& p){
  Polynomial tempP = *this;
  for(int i=0; i<p.number_of_terms(); i++){
    tempP = tempP + p[i];
  }
  return tempP;
}

Polynomial Polynomial::operator*(int z) {
  Polynomial tempP = *this;
  for(int i=0; i<tempP.number_of_terms(); i++){
    tempP[i].set_coefficient(tempP[i].get_coefficient() * z);
  }
  tempP.leading_term.set_coefficient(leading_term.get_coefficient() * z);
  return tempP;
}

Polynomial Polynomial::operator-(Polynomial& p){ //TODO since I am passing by reference I need to be careful that I am not changing
  Polynomial tempP = *this;
  Polynomial tempP2 = p*(-1);
  tempP = tempP + tempP2;
  tempP.simplify();
  return tempP;
}

Polynomial Polynomial::operator*(Term& t){
  Polynomial tempP = *this;
std::cout << "polynomial*term:  " << tempP << " " << t << std::endl;
  for(int i=0; i < number_of_terms() ; i++){
    std::cout << "  multiplying: " << tempP[i] << " with " << t << std::endl;

    tempP[i] = tempP[i]*t;
    std::cout <<"result is " << tempP[i] << std::endl;
  }
  tempP.leading_term = leading_term*t;
  return tempP;
}

void Polynomial::simplify_coefficients(){
  if(number_of_terms()>=2){
    int gcd = GCD(polynomial[0].get_coefficient(),polynomial[1].get_coefficient());
    for(int i=2; i<number_of_terms(); i++){
      gcd = GCD(gcd, polynomial[i].get_coefficient());
    }
    gcd = ABS(gcd);
    if(gcd != 1) {
      for(int i=0; i<number_of_terms(); i++){
        if(polynomial[i].get_coefficient()/gcd == 0){
          std::cout << "ERROR: GCD(A,B) > A OR B" << std::endl;
        }
        polynomial[i].set_coefficient(polynomial[i].get_coefficient()/gcd);
      }
    }
    if(leading_term.get_coefficient()/gcd == 0){
      std::cout << "ERROR: GCD(A,B) > A OR B" << std::endl;
    }
    leading_term.set_coefficient(leading_term.get_coefficient()/gcd);
  }
  else if (number_of_terms() == 1){
    polynomial[0].set_coefficient(1);
    leading_term = polynomial[0];
  }
}

/*
Polynomial Polynomial::operator*(Polynomial& p){
  Polynomial tempP = Polynomial();
  for(int i=0; i<polynomial.size(); i++){
      for(int k=0; k<p.size(); k++){
        Term tempT = polynomial[i]*p[k];
        tempP+=tempT;
      }
    }
    return *this;
}
//Polynomial& Polynomial::operator*=(Term& t){}
Polynomial Polynomial::operator*(int i){
  for(int i=0; i<number_of_terms; i++){
    p[i] = p[i]*(-1);
  }
  return *this;
}

*/
void Polynomial::simplify(){
  int index = 0;
  while(index < number_of_terms()-1){
    int next = index + 1;
    while(next < number_of_terms()){
      if(polynomial[index].share_monomial(polynomial[next])){
        polynomial[index] = polynomial[index] + polynomial[next];
        polynomial.erase(polynomial.begin() + next);


        if(polynomial[index].get_coefficient() == 0){
          polynomial.erase(polynomial.begin()+index);
          Term lt = polynomial[0];
          for(int j=1; j<number_of_terms(); j++){
            if(polynomial[j] > lt){
              lt = polynomial[j];
            }
          }
          leading_term = lt;
          next = index;
        }

      }
      next++;
    }
    index++;
    }
}

/*Polynomial& Polynomial::make_primitive(){}

*/
/********************
RELATIONS
********************/

bool Polynomial::operator<(Polynomial& p){
  return leading_term < p.leading_term; //might need to fix how terms are compared
}
bool Polynomial::operator>(Polynomial& p){
  return leading_term > p.leading_term;
}

/*
bool Polynomial::operator==(Polynomial& p){

}
*/

/********************
Display
********************/
std::ostream& operator<<(std::ostream& output, Polynomial& p){
  for(int i=0; i<p.number_of_terms(); i++){
    std::string sign;
    if(p[i].get_coefficient() < 0){
      sign = ""; //negative
    }
    else {
      sign = "+";
    }
    output << sign << p[i];
  }
  return output;
}

QString Polynomial::toQString() const {
    QString output = "";
    QString sign="";

    for(int i=0; i< polynomial.size(); i++){
      if(polynomial[i].get_coefficient() > 0){
        sign = "+";
      } else { sign = "";}
      output +=sign+ polynomial[i].toQString();
    }
    return output;
}
