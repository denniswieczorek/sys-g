#ifndef TERM_H
#define TERM_H

#include "Monomial.h"

class Term
{
  public:
    Term();
    ~Term();
    Term(int);
  private:
    Monomial monomialPart;
    int coeff;


};

#endif
