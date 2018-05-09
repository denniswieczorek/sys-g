#include "Controller.h"
#include "Xn.h"
#include "Monomial.h"
#include "Polynomial.h"

Controller::Controller()
{
	init();
}

void Controller::launch() {
	
	int choice;

	while(1) {
		choice =-1;
		view.mainMenu(choice);
	
		if (choice == 1) {
			//view.printXns(xl);
			//view.printMonomial(mm);	
		//	view.printMonomials(ml);		
		//	view.printPoly(poly);			
			view.printIdeal(J);			
			view.pause();
		} 
	
		else {
			break;
		}

	}
}





void Controller::init()
{
	/*
	Polynomial* newP,*newP2,*newP3, *tp;
	Monomial* newM; 
	Xn* newVar;
	

	//(x^2)(y^4)(z^3)
	newP = new Polynomial();
	newM =  new Monomial(1);
	newVar = new Xn(1,2);
	*newM+=(newVar);
	newVar = new Xn(1,3);
	*newM+=newVar;
	newVar = new Xn(2,4);	
	*newM+=(newVar);
	newVar = new Xn(3,3);	
	*newM+=(newVar);
	*newP+=(newM);

	//(x^2)(y^4)(z^3)

	newM =  new Monomial(1);
	newVar = new Xn(1,2);
	*newM+=(newVar);
	newVar = new Xn(2,4);	
	*newM+=(newVar);
	newVar = new Xn(3,3);	
	*newM+=(newVar);
	*newP+=(newM);
	
	//1(x^2)(y^3)

	newM =  new Monomial(1);
	newVar = new Xn(1,2);
	*newM+=(newVar);
	newVar = new Xn(2,3);	
	*newM+=(newVar);
	*newP+=(newM);
		


	//3(x^2)(y^3)

	newM =  new Monomial(3);	
	newVar = new Xn(1,2);
	*newM+=(newVar);
	newVar = new Xn(2,3);
	*newM+=newVar;	
	*newP+=(newM);

	//1(x^2)(y)

	newM = new Monomial(1);
	newVar = new Xn(1,2);
	*newM+=newVar;
	newVar = new Xn(2,1);
	*newM+=newVar;
	*newP+=newM;

	//2x

	newM = new Monomial(2);
	newVar = new Xn(1,1);
	*newM+=newVar;
	*newP+=newM;

	//y^3

	newM = new Monomial(1);
	newVar = new Xn(2,3);
	*newM+=newVar;
	*newP+=newM;
	
	//xy^3

	newM = new Monomial(1);
	newVar = new Xn(1,1);
	*newM+=(newVar);
	newVar = new Xn(2,3);
	*newM+=newVar;
	*newP+=newM;

	//-3x^2y^3
	
	newM = new Monomial(-3);
	newVar = new Xn(1,2);
	*newM+=newVar;
	newVar = new Xn(2,3);
	*newM+=newVar;
	*newP+=newM;

	Monomial *t1;
	t1 = new Monomial(3);
	newVar = new Xn(1,3);
	*t1+=newVar;
	*newP*t1;



	J+=newP;
	//2x^2
	newP3 = new Polynomial();
	newM = new Monomial(2);
	newVar = new Xn(1,2);
	*newM+=newVar;
	*newP3+=newM;

	//y^5
	newM = new Monomial(1);
	newVar = new Xn(2,5);
	*newM+=newVar;
	*newP3+=newM;
	
	//x^3y^3
	newM = new Monomial(1);
	newVar = new Xn(1,3);
	*newM+=(newVar);
	newVar = new Xn(2,3);
	*newM+=newVar;
	*newP3+=newM;

	//-3xy^3
	newM = new Monomial(-3);
	newVar = new Xn(1,1);
	*newM+=newVar;
	newVar = new Xn(2,3);
	*newM+=newVar;
	*newP3+=newM;

	J+=newP3;
	
	
	//(x)(y)(z)
	newP2 = new Polynomial();
	newM =  new Monomial(1);
	newVar = new Xn(1,1);
	*newM+=(newVar);
	newVar = new Xn(2,1);	
	*newM+=(newVar);
	newVar = new Xn(3,1);	
	*newM+=(newVar);
	*newP2+=(newM);
	
	//1(x^2)(y^3)

	newM =  new Monomial(1);
	newVar = new Xn(1,2);
	*newM+=(newVar);
	newVar = new Xn(2,3);	
	*newM+=(newVar);
	*newP2+=(newM);
		


	//3(x)(y^3)


	newM =  new Monomial(3);	
	newVar = new Xn(1,1);
	*newM+=(newVar);
	newVar = new Xn(2,3);
	*newM+=newVar;	
	*newP2+=(newM);

	J+=newP2;

	//2(x^2)+4xy
	newP = new Polynomial();
	newM = new Monomial(2);
	newVar = new Xn(1,2);
	*newM+=newVar;
	*newP+=newM;
	newM = new Monomial(4);
	newVar = new Xn(1,1);
	*newM+=newVar;
	newVar = new Xn(2,1);
	*newM+=newVar;
	*newP+=newM;
	
	//3(x^3)
	t1 = new Monomial(3);
	newVar = new Xn(1,3);
	*t1+=newVar;	
	*newP*t1;//
	*newP-newP2; // 
			

	
	
	J+=newP;

	
	
	Polynomial *pp1, *pp2, *pp3;
	Monomial *mm1, *mm2;
	pp1 = new Polynomial();
	mm1 = new Monomial(2);
	newVar = new Xn(1,2);
	*mm1+=newVar;
	*pp1+=mm1;	
	newVar = new Xn(1,1);
	*mm1+=newVar;
	newVar = new Xn(2,1);
	*mm1+=newVar;
	*pp1+=mm1;
	newVar = new Xn(2,2);
	*mm1+=newVar;
	*pp1+=mm1;
	J+=pp1;

	pp2 = new Polynomial();
	mm2 = new Monomial(1);
	newVar = new Xn(2,3);
	*mm2+=newVar;
	*pp2+=mm2;
	newVar = new Xn(1,1);
	*mm2+=newVar;
	newVar = new Xn(2,1);
	*mm2+=newVar;
	*pp2+=mm2;
	J+=pp2;

	mm1 = new Monomial(1);
	newVar = new Xn(1,1);
	*mm1+=newVar;
	mm2 = new Monomial(1);
	newVar = new Xn(2,1);
	*mm2+=newVar;
	
	
	pp3 = new Polynomial();
//	*pp3 = ((*pp2*mm1)-(*pp1*mm2));
	pp3 = pp2;
	mm1 = new Monomial(1);
	newVar = new Xn(1,1);
	*mm1+=newVar;
	newVar = new Xn(2,1);
	*mm1+=newVar;

	*pp3+=mm1;
	
	J+=pp3;

*/
	














	

	
}

