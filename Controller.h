#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "View.h"
#include <iostream>

#include "Ideal.h"

class Controller
{
	public:
		Controller();
		void launch();
	private:
		View view;
		void init();
		Ideal J;

};

#endif
