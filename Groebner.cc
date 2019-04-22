#include "Groebner.h"


//TODO need to be able to delete members when they are zero or completely reduce polynomial and add only if it doesn't reduce to zero
//TODO fix polynomial id's so that checking comparison will work in all cases
/********************
CONSTRUCTOR
********************/

/********************
MODIFIERS
********************/


void Groebner::buchberger(){
 // while(allResolventsComputed() == 0){
      std::cout << "entering algorithm" << std::endl;
    reduce_ideal();
    compute_resolvents();
   // reduce_ideal();
  //}
}

int Groebner::allResolventsComputed() {
    int s = ideal.size();
    if(s == 1){
        return 1;
    }
    else if(comparisons.size() < (s*(s-1))/2){
        return 0;
    }
    for(unsigned int i=0; i<comparisons.size(); i++){
        for(unsigned int j=i+1; j<comparisons.size(); j++){
            if(check_if_resolvent_computed(ideal[i],ideal[j]) == 0){
                return 0;
            }
        }
    }
    return 1;
}


/*
void Groebner::buchberger1(){
    int i =0;
    int j=0;
    while(i<number_of_members() || j < number_of_members()){
        if(i!=j){
            if(ideal[i].number_of_terms() == 0){
                ideal.erase(ideal.begin()+i);
            }else if(ideal[j].number_of_terms()==0){
                ideal.erase(ideal.begin()+j);
            } else {
                ideal[i].simplify_coefficients();
                ideal[j].simplify_coefficients();
                if(reduce_polynomials(ideal[i],ideal[j])==1){
                    i=0;
                    j=0;
                }
            }
        }
        else if(j==number_of_members()-1){
            j=0;
            i++;
        }
        else {
            j++;
        }
    }
}

*/
void Groebner::reduce_ideal(){
  //make every function primitive

  for(int i = 0; i< number_of_members(); i++){
    for(int j=0; j<number_of_members(); j++){
      if(i!=j){
        if(ideal[i].number_of_terms() == 0){
          ideal.erase(ideal.begin()+i);
        }
        else if(ideal[j].number_of_terms() == 0){
          ideal.erase(ideal.begin() + j);
        }
        else{
          ideal[i].simplify_coefficients();
          ideal[j].simplify_coefficients();
          if(reduce_polynomials(ideal[i], ideal[j]) == 1){

            i =0;
            j =0;
          }
        }
      }
    }
  }
}


int Groebner::compute_resolvent(Polynomial& f, Polynomial& g){
    std::cout << " computing resolvenet" << std::endl;
  Term ft = f.get_leading_term();
  Term gt = g.get_leading_term();

  Term f_factor = gt%ft;
  f_factor.set_coefficient(LCM(gt.get_coefficient(), ft.get_coefficient())/ft.get_coefficient());
  Term g_factor = ft%gt;
  g_factor.set_coefficient(LCM(gt.get_coefficient(), ft.get_coefficient())/gt.get_coefficient());

  Polynomial resolvent = Polynomial();
  resolvent = (f*f_factor);
  Polynomial p2 = g*g_factor;
  resolvent = resolvent - p2;
  std::vector<int> comp;
  comp.push_back(f.get_poly_id());
  comp.push_back(g.get_poly_id());
  comparisons.push_back(comp);
    std::cout << "      resolvent = " << resolvent << std::endl;
  if(!(resolvent.number_of_terms() == 0)){
    addPolynomial(resolvent);
    return 1;
  }
  return 0;
}

int Groebner::check_if_resolvent_computed(Polynomial& f, Polynomial& g){
  for(int i=0; i<comparisons.size(); i++){
    if(comparisons[i].size() == 2){
      if(f.get_poly_id() == comparisons[i][0] || f.get_poly_id() == comparisons[i][1]){
        if(g.get_poly_id() == comparisons[i][0] || g.get_poly_id() == comparisons[i][1]){
          return 1;
        }
      }
    }
  }
  return 0;
}

int Groebner::compute_resolvents(){
  if(number_of_members() >=2){
    int base = 0;
    while(base < number_of_members() - 1){
      int next = base+1;//TODO FIX THE POLY IDS
      while(next < number_of_members()){
      if(check_if_resolvent_computed(ideal[base], ideal[next]) == 0){
          return compute_resolvent(ideal[base], ideal[next]);
        }
        else{
          next++;
        }
      }
      base++;
    }
  }
  return 0;
}




int Groebner::reduce_polynomials(Polynomial& f, Polynomial& g){
  if(f > g){
    return reduce_polynomial_by_leading_term(f,g);
  }
  else {
    return reduce_polynomial_by_leading_term(g,f);
  }
}

/*
//reduce_polynomial(F)

//reduce_polynomial_by_leading_term -- prioritize this
*/
int Groebner::reduce_polynomial_by_non_leading_term(Polynomial& f, Polynomial& g){
  //f > g
  //check to see if term in f can be removed by reducing with leading term of g
    std::cout << "attempting to reduce by non-leading f=" << f << " with g="<<g <<std::endl;
  for(int i=0; i < f.number_of_terms(); i++){
    Term factor = compute_difference(f[i], g.get_leading_term());
    if(!(factor == 0)){
      int comm = ABS(LCM(f[i].get_coefficient(), g.get_leading_term().get_coefficient()));
      f = f* (comm/f[i].get_coefficient());
      g = g * (comm/g.get_leading_term().get_coefficient());
      Polynomial reduced_poly = g*(factor);
      reduced_poly = f - reduced_poly;
      std::cout << "         factor = " << factor << std::endl;
      std::cout << "        reduced polynomial = " << reduced_poly << std::endl;
      f = reduced_poly;
      return 1;
    }
  }
  return 0;
}
//Reducing polynomial f
int Groebner::reduce_polynomial_by_leading_term(Polynomial& f, Polynomial& g){
   std::cout << "attempting to reduce f=" << f << " with g=" << g << std::endl;
  if(!(f > g)){
    return 0;
  }
  Term factor = compute_difference(f.get_leading_term(), g.get_leading_term());
  if(factor == 0){
      std::cout << "cannot reduce by leading terms" << std::endl;
    return reduce_polynomial_by_non_leading_term(f,g);
  }
  //TODO clean this up
  int comm = ABS(LCM(f.get_leading_term().get_coefficient(), g.get_leading_term().get_coefficient()));

  std::cout << "        " << comm/f.get_leading_term().get_coefficient() << "[" << f <<"]" << "     -    " << comm/g.get_leading_term().get_coefficient() << "(" << factor << ")["<< g  << "]" << std::endl;
  f = f* (comm/f.get_leading_term().get_coefficient());
  g = g * (comm/g.get_leading_term().get_coefficient());

  Polynomial reduced_poly = (g*(factor));

  std::cout << "        " << f  << "     -    " << reduced_poly  << std::endl;
  reduced_poly = f - reduced_poly;

  std::cout << "        " << reduced_poly  << std::endl;
  g.simplify_coefficients();

  std::cout << "        reduced polynomial = " << reduced_poly << std::endl;
  f = reduced_poly;
  return 1;
}


//Assuming that t1 > t2
Term Groebner::compute_difference(Term t1, Term t2){ //should change this to a terms thing
  //TODO probably don't want this as first term can be multiplied to make like term
  if(t1 > t2 || t1.share_monomial(t2)){
    std::cout << "calcluatoing diff btwn  " << t1 << " and " << t2 << std::endl;
    Term newFactor = t1/t2;
    std::cout << " result is " << newFactor << std::endl;
    return newFactor;
  }
  else {
    return 0;
  }
}



/********************
DISPLAY
********************/
