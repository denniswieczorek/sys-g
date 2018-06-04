#include "Grobner.h"

Grobner::Grobner()
{}


void Grobner::initGrobnerBasis(Ideal J)
{
	G = J;
}



Polynomial* Ideal::computeResolvent(Polynomial& f, Polynomial& g)
{

	Monomial* fm = f.getLeadingTerm();
	Monomial* gm = g.getLeadingTerm();

	int lcm = LCM(fm->getCoeff(),gm->getCoeff());
	Monomial *gFactor = new Monomial(lcm/gm->getCoeff()); // compute
	Monomial *fFactor = new Monomial(lcm/fm->getCoeff());
	int difference = 0;
	Xn* newX;
	for(int i=1; i<(fm->getNumVars() > gm->getNumVars()  ? fm->getNumVars() +1 : gm->getNumVars() + 1 ); i++){
		if(fm->getDeg(i) >= gm->getDeg(i)) {
			difference = fm->getDeg(i) - gm->getDeg(i);
			newX = new Xn(i, difference);
			*gFactor+=newX;
		}
		else {
			difference = gm->getDeg(i) - fm->getDeg(i);
			newX = new Xn(i, difference);
			*fFactor+=newX;
		}
	}
	Polynomial* rp = new Polynomial;
	*rp = *(*(f*fFactor) - (g*gFactor));

	return rp;


}


std::ostream& operator<<(std::ostream& output, Grobner& J)
{
	output << J.G << std::endl;

	return output;
}
