#ifndef XN_H
#define XN_H

#include <iostream>
#include <sstream>
#include <QString>

class Xn {

  friend std::ostream& operator <<(std::ostream&, const Xn&); //allows for object info to be streamed out
  public:
    //CONSTRUCTOR
    Xn(int, int);  //for Xn(i,e) sets id to i and exponent to e
    Xn(std::string);
    //ACCESS
  //int get_max_id() const;   // returns the max_id that has been set
    int get_exponent() const; // returns the variables exponent
    int get_id() const;       // returns the id for the variable
    QString toQString() const;
    //MODIFIERS
    void set_exponent(int&);   // sets the exponent to a new integer
    Xn operator*(Xn&);
    //RELATIONS FUNCTIONS
    bool shares_variable(Xn&) const;  // returns true if they have the same variable type i.e. same id
    bool appears_before(Xn&) const;   // returns true if this.id is less than the one being compared to
    bool operator<(Xn&) const;        // returns true if are of the same variable and has lesser exponent
    bool operator>(Xn&) const;        // returns true if are of the same variable has a greater exponent
    bool operator==(Xn&) const;       // returns true if are of the same variable and have equivalent exponents

  private:
    unsigned int id;            // id = n in Xn
    int exponent;      //exponent has to be greater than 0
    static int max_id; //Static variables to prevent skipping in id
};

#endif
