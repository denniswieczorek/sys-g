#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "View.h"
#include <iostream>

#include "Ideal.h"
#include "Grobner.h"

class Controller
{
	public:
		Controller();
		void launch();
	private:
		View view;
		void init();
		void runTest();
		Ideal J;
		Grobner G;

};

#endif
