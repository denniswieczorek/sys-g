#ifndef TEST_H
#define TEST_H

#include "LinkedList.h"
#include "Monomial.h"
#include "Polynomial.h"
#include "Xn.h"
#include "Ideal.h"


void Test1(Ideal& J) // test that we can do simple appending to the ideal
{
	Polynomial* newP;
	Monomial* newM;
	Xn* newX;
	

	//f=(x^2)(y^4)(z^3) + 2x^2 + x^2 + xy + -5z^2 + 1
	newP = new Polynomial();
		

	//(x^2)(y^4)(z^3)
	newM = new Monomial(1);
	newX = new Xn(1,2); //x = 1, y = 2, z = 3
	*newM+=newX;
	newX = new Xn(2,4);
	*newM+=newX;
	newX = new Xn(3,3);
	*newM+=newX;
	*newP+=newM;

	//2x^2
	newM = new Monomial(2);
	newX = new Xn(1,2);
	*newM+=newX;
	*newP+=newM;

	//x^2
	newM = new Monomial(1);
	newX = new Xn(1,2);	
	*newM+=newX;
	*newP+=newM;
	
	//xy
	newM = new Monomial(0);
	newX = new Xn(1,1);
	*newM+=newX;
	newX = new Xn(2,1);
	*newM+=newX;
	*newP+=newM;
	
	//-5z^2
	newM = new Monomial(-5);
	newX = new Xn(3,2);
	*newM+=newX;
	*newP+=newM;

	//1
	newM = new Monomial(1);
	*newP+=newM;

	J+=newP;

}	
void Test2(Ideal& J) // test that we can do simple appending to the ideal
{
	Polynomial* newP;
	Monomial* newM;
	Xn* newX;
	//J=<f,g>

	//f=(x^2)(y^4)(z^3) + 2x^2 + x^2 + xy + -5z^2 + 1
	newP = new Polynomial();
		

	//(x^2)(y^4)(z^3)
	newM = new Monomial(1);
	newX = new Xn(1,2); //x = 1, y = 2, z = 3
	*newM+=newX;
	newX = new Xn(2,4);
	*newM+=newX;
	newX = new Xn(3,3);
	*newM+=newX;
	*newP+=newM;

	//2x^2
	newM = new Monomial(2);
	newX = new Xn(1,2);
	*newM+=newX;
	*newP+=newM;

	//x^2
	newM = new Monomial(1);
	newX = new Xn(1,2);	
	*newM+=newX;
	*newP+=newM;
	
	//xy
	newM = new Monomial(0);
	newX = new Xn(1,1);
	*newM+=newX;
	newX = new Xn(2,1);
	*newM+=newX;
	*newP+=newM;
	
	//-5z^2
	newM = new Monomial(-5);
	newX = new Xn(3,2);
	*newM+=newX;
	*newP+=newM;

	//1
	newM = new Monomial(1);
	*newP+=newM;

	J+=newP;
/* ******************************* */
	//g=-xy-xx+zzz+xx 
	newP = new Polynomial();

	//-xy
	newM = new Monomial(-1);
	newX = new Xn(1,1);
	*newM+=newX;
	newX = new Xn(2,1);
	*newM+=newX;
	*newP+=newM;
	
	//-xx
	newM = new Monomial(-1);
	newX = new Xn(1,1);
	*newM+=newX;
	newX = new Xn(1,1);
	*newM+=newX;
	*newP+=newM;
	
	//zzz
	newM = new Monomial(1);
	newX = new Xn(3,1);
	*newM+=newX;
	newX = new Xn(3,1);
	*newM+=newX;
	newX = new Xn(3,1);
	*newM+=newX;
	*newP+=newM;

	//xx
	newM = new Monomial(1);
	newX = new Xn(1,1);
	*newM+=newX;
	newX = new Xn(1,1);
	*newM+=newX;
	*newP+=newM;

	J+=newP;
	
	newP = new Polynomial();
	
	//*newP+=newM;
	J+=newP;




}	

/*
NTBRW
*/


//Test the simplification of a monomial
void Test3(Ideal& J)
{
	Polynomial* newP;
	Monomial* newM, *secM;
	Xn* newX;
	
	newP = new Polynomial();	
	secM = new Monomial(1);
	newX = new Xn(2,2);
	*secM+=newX;
	newX = new Xn(2,2);
	*secM+=newX;
	//delete secM;
	newM = new Monomial(1);
	newX = new Xn(1,1);
	*newM+= newX;
	newX = new Xn(1,1);
	*newM+=newX;
	//std::cout << secM << < std::endl;
	*newM = *secM;
//	delete secM;
	//newM->simplify();
//	std::cout << secM << std::endl;
		
	

	*newP+=newM;
	J+=newP;
}


#endif	


