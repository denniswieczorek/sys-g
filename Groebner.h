#ifndef GROEBNER_H
#define GROEBNER_H

#include "helper.h"
#include "Ideal.h"
#include "Polynomial.h"
#include "Term.h"



class Groebner : public Ideal {
  public:
  
    Term compute_difference(Term, Term);
    int reduce_polynomial_by_leading_term(Polynomial&, Polynomial&);
    int reduce_polynomials(Polynomial&, Polynomial&);
    int compute_resolvent(Polynomial&, Polynomial&);
    int compute_resolvents();
    int check_if_resolvent_computed(Polynomial&, Polynomial&);
    int reduce_polynomial_by_non_leading_term(Polynomial&, Polynomial&);
    void reduce_ideal();
    void buchberger();
    int allResolventsComputed();

  private:
     std::vector<std::vector<int>>  comparisons;
};

#endif
