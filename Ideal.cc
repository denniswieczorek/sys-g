#include "Ideal.h"
#include <iostream>
/********************
CONSTRUCTOR
********************/
Ideal::Ideal() {}
/********************
ACCESS
********************/
const std::vector<Polynomial>& Ideal::members() const { return ideal; }
int Ideal::number_of_members() const { return ideal.size(); }
Polynomial& Ideal::operator[](unsigned int i) { return ideal[i]; }
/********************
MODIFIERS
********************/
void Ideal::addPolynomial(Polynomial& p) {
  ideal.push_back(p);
}
void Ideal::clear() {
    ideal.clear();
}
/********************
DISPLAY
********************/
std::ostream& operator<<(std::ostream& output, Ideal& j){
  output << "< ";
  for(int i=0; i< j.number_of_members(); i++){
    output << j[i] << ", ";
  }
  output << ">";
  return output;
}

QString Ideal::toQString()  {
    QString output = "";
    for(int i=0; i< ideal.size(); i++){
      output += ideal[i].toQString() + ", ";
    }
   output = "<" + output + ">";
    return output;
}
