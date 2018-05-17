#include "Controller.h"
#include "Xn.h"
#include "Monomial.h"
#include "Polynomial.h"
#include "test.h"

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
		else if (choice == 2) {
			J.simplify();
			view.pause();		

			} 
	
	
		else {
			break;
		}

	}
}





void Controller::init()
{
	//Test1(J);
	//Test2(J);	
	//Test3(J); //will re write
	Test4(J);

}

