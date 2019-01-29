#ifndef TERM_H
#define TERM_H

#include "Xn.h"
#include <vector>

class Term {
  public:
    //CONSTRUCTOR
    Term();
    Term(int);  //for Term(i) sets coefficient to i

    //ACCESS
  //  int max_variable() const; //will be used to determine the number of variables that make up a polynomial
    int number_of_variables() const;
    int size() const; //returns number of variables that have non-zero exponent
    int get_coefficient() const; //returns the terms coefficent
    const std::vector<Xn>& members() const; // returns the variables that have a non-zero exponent
    Xn& operator[](unsigned int); //returns indexed element
    int get_degree() const; //returns the sum of exponents
    int get_degree_of_X(unsigned int) const; //called for i returns the exponent of Xn with Xn.id = i
    //MODIFIERS
    void set_coefficient(int); //sets the coefficient to a new integer
    //Term& operator*=(Xn&); //adds a Xn to mono
    Term operator*(Xn&);
    Term operator+(Term&);
    //void operator/=(Xn&);
    Term operator%(Xn&);
    Term operator%(Term);
    Term operator/(Xn&); //takes away Xn from mono
    Term operator/(Term);
    //void operator*=(Term&); //multiplies Term by another term
    Term operator*(Term&);

    //void operator*=(int); //multiplies Term by int
    Term operator*(int);
    //Term& simplify();
    //RELATIONS FUNCTIONS
    bool share_monomial(Term&) const; // 3xy = 4xy
    bool operator==(int) const;
    bool operator==(Term&) const; //compares monomial and coefficient == 3xy = 3xy
    bool operator<(Term&) const; // lexigraphical order
    bool operator>(Term&) const; // lex = coefficient*zigraphical order


  private:
    int coefficient;
    int degree;
    std::vector<Xn> monomial;
    static int max_variable;

  friend std::ostream& operator<<(std::ostream&, Term&);

};

#endif
