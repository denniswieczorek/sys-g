OBJ = main.o Groebner.o Ideal.o Polynomial.o Term.o Xn.o

test: $(OBJ)
	g++ -o test $(OBJ)

main.o: main.cc
	g++ -c main.cc

Groebner.o: Ideal/Groebner.cc Ideal/Groebner.h
	g++ -c Ideal/Groebner.cc

Ideal.o: Ideal/Ideal.cc Ideal/Ideal.h
	g++ -c Ideal/Ideal.cc

Polynomial.o: Polynomial/Polynomial.cc Polynomial/Polynomial.h 
	g++ -c Polynomial/Polynomial.cc

Term.o: Polynomial/Term.cc Polynomial/Term.h 
	g++ -c Polynomial/Term.cc

Xn.o: Polynomial/Xn.cc Polynomial/Xn.h
	g++ -c Polynomial/Xn.cc



clean:
	rm -f $(OBJ) test
