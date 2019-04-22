 #ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"
#include <vector>
#include "helper.h"

class Polynomial {

public:
  //CONSTRUCTOR
  Polynomial();
  Polynomial(std::string);
  //Polynomial(std::vector<Term>&)
  //ACCESS
  int get_poly_id() const;
  int number_of_terms() const;
  int get_degree() const; //returns the degree of the leading
  Term& get_leading_term() ;// returns the term with the greatest get_degree
  const std::vector<Term>& members() const;
  Term& operator[](unsigned int);
  //MODIFIERS
  Polynomial& make_primitive(); // reduce polynomial to primitive form
  void simplify();
  Polynomial operator+(Term&);
  Polynomial operator+(Polynomial&);
  Polynomial operator-(Polynomial&);
  Polynomial operator*(Polynomial&);
  Polynomial operator*(Term&);
  Polynomial operator*(int);
  void simplify_coefficients();
  QString toQString() const;
  //RELATIONS
  bool operator<(Polynomial&);
  bool operator>(Polynomial&);
  bool operator==(Polynomial&);


private:
  std::vector<Term> polynomial;
  Term leading_term;
  int poly_id;
  static int id_incrementer;
friend std::ostream& operator<<(std::ostream&, Polynomial&);
};
#endif
