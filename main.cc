#include <iostream>
#include "Polynomial/Xn.h"
#include "Polynomial/Term.h"
#include "Polynomial/Polynomial.h"
#include "Ideal/Ideal.h"
#include "Ideal/Groebner.h"

int main() {


  /*
  TERM CAN'T BE ADJUSTED AFTER NEXT TERM HAS BEEN DECLARED
  */
  //I = < x^2y, x-y-1>
  int num_polys = 0;
  int num_vars = 0;
  std::cout << "Enter the number of polynomials in your ideal: ";
  //std::cin >> num_polys;

  std::cout << "Enter the number of variables: ";
  //std::cin >> num_vars;
  std::string str ;
  //std::cin >> str;

  std::cout << str << std::endl;
  Groebner gg = Groebner();
//  for(int i=0; i < num_polys; i++){
  //  Polynomial p = Polynomial();

//  }

  Polynomial p = Polynomial();
  Term t = Term(1);
  Xn x = Xn(0,2);
  t = t*x;
  p = p+t;
  t = Term(1);
  x = Xn(1,2);
  t = t*x;
  p = p+t;
  t = Term(-1);
  p = p+t;
  gg.addPolynomial(p);

  p = Polynomial();
  t = Term(1);
  x = Xn(0,1);
  t = t*x;
  x = Xn(1,1);
  t = t*x;
  p = p+t;
  gg.addPolynomial(p);

  p = Polynomial();
  t = Term(1);
  x = Xn(0,3);
  t = t*x;
  p = p+t;
  t = Term(-1);
  x = Xn(0,1);
  t = t*x;
  p = p+t;
  gg.addPolynomial(p);



/*
  Polynomial p = Polynomial();
  Term t = Term(1);
  Xn x = Xn(0,1);
  t = t*x;
  x = Xn(1,1);
  t = t*x;
  p = p+t;
  t = Term(1);
  x = Xn(0,1);
  t = t*x;
  p = p+t;
  t = Term(-2);
  p = p+t;
  gg.addPolynomial(p);
  p = Polynomial();
  t = Term(1);
  x = Xn(0,2);
  t = t*x;
  p = p+t;
  t = Term(-1);
  p = p+t;
  gg.addPolynomial(p);

  std::cout << gg << std::endl;
*/
/*
  Polynomial p1 = Polynomial();
  Term t1 = Term(1);
  Xn x2 = Xn(0,2);
  Xn y =  Xn(1,1);
  t1 = t1*x2;
  t1 = t1*y;
  p1 = p1 + t1;
  gg.addPolynomial(p1);

  p1 = Polynomial();
  Term tt1 = Term(1);
  Xn x = Xn(0,1);
  tt1 = tt1*x;
  Term tt2 = Term(-1);
  Xn yy = Xn(1,1);
  tt2 = tt2*yy;
  Term tt3 = Term(-1);
  p1 = ((p1 + tt1) + tt2) + tt3;
  gg.addPolynomial(p1);

*/




  gg.buchberger();








  return 0;

}
