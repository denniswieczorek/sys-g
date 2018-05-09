#include "PolynomialList.h"

PolynomialList::PolynomialList() : head(0) {}
PolynomialList::~PolynomialList()
{
	Node* currNode, *nextNode;
	
	currNode=head;
	
	while(currNode != 0) {
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	}	
}

PolynomialList::PolynomialList(const PolynomialList& oldPL)
{

	Node* oldCurrNode, *oldNextNode;
	Node* currNode, *nextNode;
	Node *newNode = new Node;
	
	//head = oldXL.head;
	currNode = head;	
	oldCurrNode = oldPL.head;
	nextNode = 0;
	while(oldCurrNode != 0){
				currNode->data = oldCurrNode->data;
				nextNode = new Node;
				nextNode = currNode->next;
				currNode = nextNode;
				oldNextNode = oldCurrNode->next;
				oldCurrNode = oldNextNode;			

	}
	//temp fix
	currNode = 0;
}

PolynomialList& PolynomialList::operator=(const PolynomialList& rhs)
{
	PolynomialList temp = rhs;
	
	Node *currNode, *nextNode, *tempCurr, *tempNext;
	
	tempCurr = rhs.head;
	currNode = head;	
		
	while(tempCurr != 0){
		currNode = tempCurr;
		currNode = currNode->next;
		tempCurr = tempCurr->next;
		return *this;
	}
}		
	

int PolynomialList::getSize() const
{
	Node* currNode = head;
	int count = 0;

	while(currNode != 0){

		currNode = currNode->next;
		count++;
	}
	
	return count;
}

void PolynomialList::operator+=(Polynomial* newPoly)
{
	Node* currNode, *prevNode;
	
	Node* newNode = new Node;
	newNode->data = newPoly;
	newNode->next = 0;
	
	currNode = head;
	prevNode = 0;

	while(currNode != 0){
		prevNode = currNode;
		currNode = currNode->next;
	}

	if(prevNode == 0){
		head = newNode;
	}
	else {
		prevNode->next = newNode;
	}
	newNode->next = currNode;
	
}	

Polynomial* PolynomialList::operator[](int index)
{
	if(index < 0 || index > (getSize() - 1)){
		return 0;
	}
 	
		
	Node *currNode = head;
	for(int i=0; i<index;i++){
		currNode = currNode->next;
	}
	return currNode->data;
}		
	

std::ostream& operator<<(std::ostream& output, PolynomialList& pl)
{	
	std::cout << "<" << std::endl;
	for(int i=0; i<pl.getSize() ;i++){
		output << (*(pl[i]))   << ", " << std::endl;
	}

	std::cout << ">" << std::endl;
	return output;
}














