#ifndef XN_LIST_H
#define XN_LIST_H

#include "Xn.h"

class XnList 
{
	friend std::ostream& operator<<(std::ostream&, XnList&);

	class Node
	{
		friend class XnList;
		private:
			Xn* 	data;
			Node* 	next;
	};

	public:
		XnList();
		~XnList();
		XnList(const XnList&);
		int getSize() const;
		XnList& operator=(const XnList&);
		Xn* operator[](int);
		XnList& operator*(XnList*);
		int getDeg();
		int getDeg(int);		
		int getLeadDeg();
		
		XnList& operator+=(Xn*);
		XnList& simplify(XnList*);
		//void operator+=(Xn*);		
		//XnList& operator-=(Xn*);
		
	private:
		Node* head;
};

#endif
