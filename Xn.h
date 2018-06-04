#ifndef XN_H
#define XN_H
#include <sstream>
#include <iostream>
#include <string> 
#include <iomanip>


class Xn
{
	public:
		Xn();
		Xn(unsigned int, int);
		~Xn();
	
		int getEx();
		int getId();
		void setEx(int);
	
		bool operator<(Xn&);
		bool operator>(Xn&);
		bool operator==(Xn&);
		friend std::ostream& operator<<(std::ostream&, Xn&);
	private:
		unsigned int id; //id = n
		int exponent;
};
#endif
