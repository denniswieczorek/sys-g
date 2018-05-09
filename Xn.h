#ifndef XN_H
#define XN_H
#include <sstream>
#include <iostream>
#include <string> 
#include <iomanip>


class Xn
{
	public:
		Xn(int, int);
		int getEx();
		int getId();
		void setEx(int);
		bool operator<(Xn&);
		bool operator>(Xn&);
		bool operator==(Xn&);
		friend std::ostream& operator<<(std::ostream&, Xn&);
	private:
		int id;
		int exponent;
};
#endif
