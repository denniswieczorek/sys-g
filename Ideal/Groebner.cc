#include "Groebner.h"


//TODO need to be able to delete members when they are zero or completely reduce polynomial and add only if it doesn't reduce to zero
//TODO fix polynomial id's so that checking comparison will work in all cases
/********************
CONSTRUCTOR
********************/

/********************
MODIFIERS
********************/
void Groebner::addPolynomial(Polynomial& p){
  ideal.push_back(p);
  unsimplified_ideal.push_back(p);
}



void Groebner::reduce_ideal(){
  std::cout<<"<REDUCE IDEAL>" << std::endl;
  std::cout << std::endl;
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
          std::cout << *this << std::endl;
          std::string str;
          std::cout << "Press enter to continue..." << std::endl;
          getline(std::cin,str);
          i =0;
          j =0;
          }
        }
      }
    }
  }
}


//Assuming that t1 > t2
Term Groebner::compute_difference(Term& t1, Term& t2){ //should change this to a terms thing
   //TODO probably don't want this as first term can be multiplied to make like term
  if(t1 > t2 || t1.share_monomial(t2)){
    Term newFactor = t1/t2;
    return newFactor;
  }
  else {
    Term newFactor(0);
    return newFactor;
  }
}

int Groebner::compute_resolvent(Polynomial& f, Polynomial& g){
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

  if(!(resolvent.number_of_terms() == 0)){
    addPolynomial(resolvent);
    return 1;
  }
  return 0;
}

int Groebner::check_if_resolvent_computed(Polynomial& f, Polynomial& g){
  std::cout << "Checking comparisons" << std::endl;
  std::cout << "======================" << std::endl;

  for(int i=0; i<comparisons.size(); i++){
    std::cout << *this << std::endl;
    std::string str;
    std::cout << "Press enter to continue...";

    getline(std::cin,str);


    if(comparisons[i].size() == 2){
      std::cout << comparisons[i][0] << "<----->" <<comparisons[i][1] << std::endl;
      std::cout << &f << "<----->" << &g << std::endl;
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
  std::cout << "<Computing Resolvents>" << std::endl;
  std::cout << std::endl;
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



void Groebner::buchberger(){
  int flag = 0;
  while(true){
    reduce_ideal();
    if(compute_resolvents() == 0){
      break;
    }


  }
}


int Groebner::reduce_polynomials(Polynomial& f, Polynomial& g){
  if(f > g){
    return reduce_polynomial_wrt(f,g);
  }
  else {
    return reduce_polynomial_wrt(g,f);
  }
}

/*
//reduce_polynomial(F)

//reduce_polynomial_by_leading_term -- prioritize this
*/
int Groebner::reduce_polynomial_by_non_leading_term(Polynomial& f, Polynomial& g){
  //f > g
  //check to see if term in f can be removed by reducing with leading term of g
  for(int i=0; i < f.number_of_terms(); i++){
    Term factor = compute_difference(f[i], g.get_leading_term());
    std::cout << factor << std::endl;
    std::cout << f[i] << " " << g.get_leading_term() << std::endl;
    if(!(factor == 0)){

      int comm = ABS(LCM(f[i].get_coefficient(), g.get_leading_term().get_coefficient()));
      std::cout << "common factor: " << comm << std::endl;
      std::cout << f[i] << std::endl;
      f = f* (comm/f[i].get_coefficient());
      g = g * (comm/g.get_leading_term().get_coefficient());
      std::cout << f << std::endl;
      std::cout << g << std::endl;


      Polynomial reduced_poly = g*(factor);
      reduced_poly = f - reduced_poly;
      f = reduced_poly;
      return 1;
    }
  }
  std::cout << "UNABLE TO REDUCE BY NON LEADING" << std::endl;
  return 0;


}
//Reducing polynomial f
int Groebner::reduce_polynomial_wrt(Polynomial& f, Polynomial& g){
  //First step will be to ensure that poly f > poly g
  std::cout << "=================" << std::endl;
  if(!(f > g)){
    std::cout << "unable to reduce " << f << " with " << g << std::endl;
    return 0;
  }
  std::cout << "Computing difference wrt leading terms polynomials <" <<f <<" , " << g << ">"  << std::endl;
  std::cout << "leading terms: " << f.get_leading_term() << " " << g.get_leading_term() << std::endl;
  Term factor = compute_difference(f.get_leading_term(), g.get_leading_term());
  std::cout << "result: " << factor << std::endl;
  if(factor == 0){
    std::cout << "Unable to reduce terms with each other by leading term" << std::endl;
    std::cout << "Checking to see if can reduce by non leading terms ..." << std::endl;
    return reduce_polynomial_by_non_leading_term(f,g);

  }

  //Second will be to compute the difference Term
    //This can be done in two ways
    //A. Reducing leading term with leading term
    //B. Reducing leading term of g with some term in f

  //TODO clean this up
  std::cout << g << std::endl;
  int comm = ABS(LCM(f.get_leading_term().get_coefficient(), g.get_leading_term().get_coefficient()));
  std::cout << "comm = " << comm << std::endl;
  std::cout << g << std::endl;
  f = f* (comm/f.get_leading_term().get_coefficient());
  g = g * (comm/g.get_leading_term().get_coefficient());
  std::cout << "new = " << f << " - " << factor << "(" << g << ")" << std::endl;

  Polynomial reduced_poly = (g*(factor));
  std::cout << "new = " << f << " - (" << reduced_poly << ")" <<  std::endl;
  reduced_poly = f - reduced_poly;
  g.simplify_coefficients();

  f = reduced_poly;

  std::cout << "new = " << reduced_poly << std::endl;
  std::cout <<"==================" << std::endl;
  return 1;
  //Third will be Subtract the two polynomials



  //Fifth will be to add the new polynomial to the groebner basis
  //Sixth will be to remove g from the groebner basis
  //Seventh will be to add new to reference ideal



}


/********************
DISPLAY
********************/
