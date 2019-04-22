#include "Term.h"

/********************
STATIC VARIABLE
********************/
int Term::max_variable = 1; //no variable id equal to *this or greater has been discovered
/********************
CONSTRUCTOR
********************/
Term::Term() {}
Term::Term(int c){
  coefficient = c;

  //initialize vector   ///bug occurs when two terms are declared side by side, i need to be able to update all objects if i wish to proceed this awayss
  for(int i=0; i<max_variable; i++){
    Xn x = Xn(i,0);
    monomial.push_back(x);
  }
  degree = 0;

}


Term::Term(std::string str){
  std::vector<std::string> xns;
  std::string vstr ="";
  //parsing
  for(unsigned int index=0; index<str.size(); index++){
    if(str[index] == '('){

      xns.push_back(vstr);
      vstr = "(";
    }
    else{
      vstr = vstr + str[index];
    }
  }
  xns.push_back(vstr); //add the last one

  int c = 1;

  if(xns[0] != ""){
  //creating
    std::istringstream css (xns[0]);
    css >> c;
  }
  coefficient = c;
  for(int i=0; i<max_variable; i++){
    Xn x = Xn(i,0);
    monomial.push_back(x);
  }
  degree = 0;
  //add xns
  for(unsigned int index=1;index<xns.size();index++){
    Xn x = Xn(xns[index]);
    *this = *this*x;
  }


}
/********************
ACCESS
********************/
//int Term::max_variable() const { return }
int Term::number_of_variables() const { return monomial.size(); } /*******review*******/
int Term::size() const { //this doesnt work
  int n = 0;
  for(int i=0; i< number_of_variables() ; i++){
    if(get_degree_of_X(i) != 0){
        n++;
    }
  }
  return n;
}
int Term::get_coefficient() const { return coefficient; }
const std::vector<Xn>& Term::members() const { return monomial; }
Xn& Term::operator[](unsigned int i)  { return monomial[i]; }

int Term::get_degree() const { return degree; }
int Term::get_degree_of_X(unsigned int id) const {
  if(id> monomial.size()){
    return 0;
  }
  return monomial[id].get_exponent();
}
/********************
MODIFIERS
********************/
void Term::set_coefficient(int c) { coefficient = c; }

Term Term::operator*(Xn& x){
  Term tempP = *this;
  int index = x.get_id();
  std::cout << tempP << " " << x <<std::endl;
  if(index+1 > max_variable){
    Xn newX = Xn(0,0);
    for(int i = max_variable; i < index+1; i++){
      newX = Xn(i,0);
      tempP.monomial.push_back(newX);
    }
    max_variable = index+1;

  }
  std::cout << x.get_exponent() << std::endl;
  int new_exponent = tempP.get_degree_of_X(index) + x.get_exponent();
  tempP[index].set_exponent(new_exponent);
  tempP.degree += x.get_exponent();
  return tempP;
}


Term Term::operator+(Term& t){
  if(share_monomial(t)){
    Term tempT = *this;
    tempT.set_coefficient(tempT.get_coefficient() + t.get_coefficient());
    return tempT;
  }
  else {
    std::cout << "Adding unlike terms" << std::endl;
    return *this;
  }
}

Term Term::operator/(Xn& x){
  Term tempT = *this;
  int index = x.get_id();
  std::cout << " inde" << index << std::endl;
  std::cout << tempT[index].get_exponent() << " - " << x.get_exponent() << std::endl;
  int new_exponent = tempT[index].get_exponent() - x.get_exponent();
  if(new_exponent<0){
    //Invalid for polynomials
    return 0;
  }

  tempT[index].set_exponent(new_exponent);
  tempT.degree -= x.get_exponent();
  return tempT;
}

Term Term::operator%(Xn& x){
  Term tempT = *this;
  int index = x.get_id();
  int new_exponent = monomial[index].get_exponent() - x.get_exponent();
  if(new_exponent < 0){
    new_exponent = 0;
  }
  tempT[index].set_exponent(new_exponent);
  return tempT;
}

Term Term::operator%(Term t){
  Term tempT = *this;
  tempT.coefficient = 1;
  for(int i=0; i<number_of_variables(); i++){
    tempT = tempT%t[i];
  }
  return tempT;
}

Term Term::operator/(Term t){
  Term tempT = *this;
  tempT.set_coefficient(1);
  for(int i=0; i< t.number_of_variables(); i++){
    std::cout << " diivivi  " << tempT << " / " << t[i] << std::endl;
    tempT = tempT/t[i];
    std::cout << "result " << tempT << std::endl;
  }
  return tempT;
}

Term Term::operator*(Term& t){
  Term tempT = Term(coefficient * t.coefficient);
  std::cout << "max_variable=" << max_variable << std::endl;
  for(int i =0; i< max_variable; i++){

    std::cout << "      monomial[i].e = " << monomial[i].get_exponent() << std::endl;
    std::cout << "      t[i].e = " << t[i].get_exponent() << std::endl;
    Xn tempX = Xn(i,monomial[i].get_exponent() + t[i].get_exponent());
    tempT = tempT * tempX;
  }
  return tempT;
}

Term Term::operator*(int z){
  Term tempT = *this;
  tempT.coefficient = tempT.coefficient*(z);
  return tempT;
}
/********************
RELATIONS
********************/
bool Term::share_monomial(Term& t) const {
  int flag = 0;
  for(int i=0; i< max_variable; i++){
    if(monomial[i].get_exponent() != t[i].get_exponent()){
      flag = 1;
      break;
    }
  }
  if(flag == 0){
    return true;
  }
  return false;
}

bool Term::operator<(Term& t) const{
  if(degree > t.degree){
    return false;
  } else if(degree < t.degree){
    return true;
  }
  for(int i=0; i<max_variable; i++){
    if(monomial[i].get_exponent() < t.monomial[i].get_exponent()){
      return true;
    } else if(monomial[i].get_exponent() > t.monomial[i].get_exponent()){
      return false;
    }
    else{
      continue;
    }
  }


  return (coefficient < t.coefficient);

}


bool Term::operator>(Term& t) const{
  return (!(*this < t));
}

bool Term::operator==(Term& t) const{
  return (!(*this<t)&&!(*this>t));
}

bool Term::operator==(int z) const{
  if(size() == 0 && coefficient == z){
    return true;
  }
  return false;
}
/********************
DISPLAY
********************/
std::ostream& operator<<(std::ostream& output, Term& t){
  output << t.coefficient;
  for(int i = 0; i < t.number_of_variables(); i++){
  //  if(t[i].get_exponent() != 0){
      output << t[i];
  //  }
  }
  return output;
}
/********************
********************/

QString Term::toQString() const {
    QString output ="";
    output += QString::number(coefficient);
    for(int i = 0; i < number_of_variables(); i++){
      if(monomial[i].get_exponent() != 0){
        output +=monomial[i].toQString();
      }
    }
    return output;
}
