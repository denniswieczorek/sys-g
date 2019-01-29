#ifndef GROEBNER_H
#define GROEBNER_H

#include "helper.h"
#include "Ideal.h"
#include "../Polynomial/Polynomial.h"
#include "../Polynomial/Term.h"



class Groebner : public Ideal {
  public:
    //MODIFIERS
    void addPolynomial(Polynomial&);

    //HELPERS
    Term compute_difference(Term&, Term&);
    int reduce_polynomial_wrt(Polynomial&, Polynomial&);
    int reduce_polynomials(Polynomial&, Polynomial&);
    int compute_resolvent(Polynomial&, Polynomial&);
    int compute_resolvents();
    int check_if_resolvent_computed(Polynomial&, Polynomial&);
    int reduce_polynomial_by_non_leading_term(Polynomial&, Polynomial&);
    void reduce_ideal();
    void buchberger();

  private:
     std::vector<Polynomial> unsimplified_ideal; //will be used to reduce polynomials with
     std::vector<std::vector<int> > comparisons;
};

#endif
