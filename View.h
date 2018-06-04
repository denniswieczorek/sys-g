#ifndef VIEW_H
#define VIEW_H

#include "Ideal.h"
#include "Grobner.h"

class View
{

	public:
		void mainMenu(int&);
		void pause() const;
		void displayInvalid();
		void printIdeal(Ideal&) const;
		void printGrobner(Grobner&) const;


	private:
		int readInt() const;
};
#endif

  public:
    Term();
    ~Term();
    Term(int);
  private:
