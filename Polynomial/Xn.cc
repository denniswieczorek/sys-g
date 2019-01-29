#include "Xn.h"
/********************
STATIC VARIABLE
*********************/
int Xn::max_id = -1;

/********************
CONSTRUCTOR
********************/
Xn::Xn(int i, int e) {
  id = i;
  exponent = e;
  //restrict gaps in id sets
  if(i > max_id || i < 0){
    if(i == max_id+1){
      max_id++;
    }
    else {
      id = -1;
      exponent = -1;
      std::cout << "Improper assignment of Xn" << std::endl;
    }
  }
}

/*********************
ACCESS
**********************/

//int Xn::get_max_id()    const { return max_id; }
int Xn::get_id()        const { return id; }
int Xn::get_exponent()  const { return exponent; }


/*********************
MODIFIERS
*********************/
void Xn::set_exponent(int& e) {  exponent = e;}

Xn Xn::operator*(Xn& x){
  if(shares_variable(x)){
      Xn newX = Xn(id,exponent + x.exponent);
      return newX;
  }
  std::cout << "WARNING: incompatible types (x." << id << ") * (x." << x.id << ")" << std::endl;
  Xn fail = Xn(0,0);
  return fail;
}
/*********************
RELATIONS
*********************/

//allows comparison between unalike elements

bool Xn::shares_variable(Xn& x) const { return id == x.id; }
bool Xn::appears_before(Xn& x) const { return id < x.id; }
bool Xn::operator<(Xn& x)  const {
  if(shares_variable(x)){
    return exponent < x.exponent;
  }
  return false;
}

bool Xn::operator>(Xn& x) const {
  if(shares_variable(x)){
    return exponent > x.exponent;
  }
  return false;
}

bool Xn::operator==(Xn& x) const {
  if(shares_variable(x)){
    return exponent == x.exponent;
  }
  return false;
}

/********************
DISPLAY
********************/
std::ostream& operator<<(std::ostream& output, const Xn&  x){
  output << "((X." << x.id << ")^" << x.exponent << ")";
  return output;
}
/********************
********************/
