#ifndef IDEAL_H
#define IDEAL_H

#include "../Polynomial/Polynomial.h"
#include <vector>

class Ideal {
  public:
    //CONSTRUCTOR
    Ideal();
    //ACCESS
    const std::vector<Polynomial>& members() const;
    int number_of_members() const;
    Polynomial& operator[](unsigned int);
    //MODIFIERS
    void addPolynomial(Polynomial&);
    void removePolynomial(Polynomial&);
  protected:
    std::vector<Polynomial> ideal;
  friend std::ostream& operator<<(std::ostream&, Ideal&);
};

#endif
