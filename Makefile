OBJ = main.o Controller.o View.o Xn.o XnList.o Monomial.o MonomialList.o Polynomial.o PolynomialList.o Ideal.o

test: $(OBJ)
	g++ -o test $(OBJ)

main.o: main.cc
	g++ -c main.cc

Controller.o: Controller.cc Controller.h View.h 
	g++ -c Controller.cc

View.o:  View.cc View.h 
	g++ -c View.cc

Xn.o: Xn.cc Xn.h
	g++ -c Xn.cc

XnList.o: XnList.cc XnList.h Xn.h
	g++ -c XnList.cc

Monomial.o: Monomial.cc Monomial.h XnList.h Xn.h
	g++ -c Monomial.cc

MonomialList.o: MonomialList.cc MonomialList.h Monomial.h 
	g++ -c MonomialList.cc

Polynomial.o: Polynomial.cc Polynomial.h Monomial.h MonomialList.h
	g++ -c Polynomial.cc

PolynomialList.o: PolynomialList.cc PolynomialList.h Polynomial.h
	g++ -c PolynomialList.cc

Ideal.o: Ideal.cc Ideal.h Polynomial.h PolynomialList.h
	g++ -c Ideal.cc


clean:
	rm -f $(OBJ) test
