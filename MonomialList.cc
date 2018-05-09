#include "MonomialList.h"

MonomialList::MonomialList() : head(0) {}

MonomialList::~MonomialList()
{
	Node* currNode, *nextNode;

	currNode = head;
	
	while(currNode != 0) {
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;	
		currNode = nextNode;
	}
}

MonomialList::MonomialList(const MonomialList& oldML )
{

	Node* oldCurrNode, *oldNextNode;
	Node* currNode, *nextNode;
	Node *newNode = new Node;
	
	//head = oldXL.head;
	currNode = head;	
	oldCurrNode = oldML.head;
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

MonomialList& MonomialList::operator=(const MonomialList& rhs)
{
	MonomialList temp = rhs;
	
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
	

MonomialList& MonomialList::negate()
{
	Node* currNode, *nextNode;
	currNode = head;
	int negatedCoeff = 0;
	while(currNode != 0) {
		negatedCoeff = currNode->data->getCoeff() *-1;
		currNode->data->setCoeff(negatedCoeff);
		nextNode = currNode->next;
		currNode = nextNode;
	}

	return *this;
}
	

Monomial* MonomialList::getLeadingTerm() { return head->data; }

		
	

MonomialList& MonomialList::operator*(Monomial *newMonomial)
{
	Node* currNode, *nextNode;
	currNode = head;
	
	while(currNode != 0){
		std::cout<<*newMonomial<<std::endl;
		*(currNode->data)*newMonomial;
		std::cout<<*newMonomial<<std::endl;
		nextNode = currNode->next;
		currNode = nextNode;
	}
	
	return *this;
}






MonomialList& MonomialList::operator+=(Monomial* newMonomial)
{
	int flag = 1; //1 if new monomial 0 if not
	int updateCoeff = 0;
	Node *currNode, *prevNode;
	Node* newNode = new Node;
	newNode->data = newMonomial;
	newNode->next = 0;

	currNode = head;
	prevNode = 0;

	while(currNode != 0) {
	
		
		if(*(newNode->data) > *(currNode->data)){
			std::cout<<"triggered > " << std::endl;
			break;
		}/*
		else if(*(newNode->data) == *(currNode->data)){
			std::cout << "triggered == " << std::endl;
			flag = 0;
			updateCoeff = newNode->data->getCoeff() + currNode->data->getCoeff();
			currNode->data->setCoeff(updateCoeff);
		}*/
		prevNode = currNode;
		currNode = currNode->next;
	}
/*	
	if(flag == 0){
		delete newNode->data;
		delete newNode;
		return *this;
	}
*/
	if(prevNode == 0){
		head = newNode;
	}
	else {
		prevNode->next = newNode;
	}
	
	newNode->next = currNode;
	
	return *this;
}


int MonomialList::getSize() const
{
	Node* currNode = head;
	int size =0;

	while(currNode != 0) {
		currNode = currNode->next;
		size++;
	}
	return size;
}

Monomial* MonomialList::operator[](int index)
{
	if(index < 0 || index > (getSize()-1)){
		return 0;
	}
	Node *currNode = head;
	for(int i =0; i<index;i++){
		currNode=currNode->next;	
	}
	return currNode->data;
}

std::ostream& operator<<(std::ostream& output, MonomialList& ml)
{
	output << *(ml[0]) << std::endl;
	for(int i=1; i<ml.getSize(); i++){
		output << "+ " << (*(ml[i])) <<std::endl;
	}
	return output; 


}
//























			 
			
