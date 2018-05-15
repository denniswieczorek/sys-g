OBJ = main.o Controller.o View.o Xn.o Monomial.o Polynomial.o Ideal.o

test: $(OBJ)
	g++ -o test $(OBJ)

main.o: main.cc
	g++ -c main.cc

Controller.o: Controller.cc Controller.h View.h test.h
	g++ -c Controller.cc

View.o:  View.cc View.h 
	g++ -c View.cc

Xn.o: Xn.cc Xn.h
	g++ -c Xn.cc


Monomial.o: Monomial.cc Monomial.h LinkedList.h Xn.h test.h
	g++ -c Monomial.cc


Polynomial.o: Polynomial.cc Polynomial.h Monomial.h LinkedList.h
	g++ -c Polynomial.cc

Ideal.o: Ideal.cc Ideal.h Polynomial.h LinkedList.h 
	g++ -c Ideal.cc


clean:
	rm -f $(OBJ) test
