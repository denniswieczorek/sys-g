# Groebner Basis Calculator

Calculate the Groebner Basis for a simple ring of polynomials

## Setup

```bash
> make
> ./Groebner
```
## Usage

Currently only supports polynomials of two variables. Type or use the buttons to create the polynomial. Syntax for Terms follow the form c(X.n)^e(X.m) where c is the coefficient, n/m is the variable number, and e is exponent. Terms can be combined together to make polynomials

e.g.
(X.0)(X.1)^2+2(X.1)+1

Press insert to add the polynomial to the ideal.

Press Groebner Basis to compute the Groebner Basis.
