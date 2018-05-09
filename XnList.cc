#include "XnList.h"

XnList::XnList() : head(0) {}

XnList::~XnList()
{
	Node* currNode, *nextNode;

	currNode = head;
	
	while(currNode  != 0) {
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	}
}


XnList::XnList(const XnList& oldXL)
{

	Node* oldCurrNode, *oldNextNode;
	Node* currNode, *nextNode;
	Node *newNode = new Node;
	
	//head = oldXL.head;
	currNode = head;	
	oldCurrNode = oldXL.head;
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


XnList& XnList::operator=(const XnList& rhs)
{
	XnList temp = rhs;
	
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
	
	


int XnList::getDeg() {
	Node* currNode, *nextNode;
	currNode = head;
	int deg =0;	

	while(currNode!=0) 	{
		deg+= currNode->data->getEx();
		nextNode = currNode->next;
		currNode = nextNode;
	}
	return deg;
}





XnList& XnList::operator*(XnList* xl)
{


}


int XnList::getDeg(int id)
{
	
	Node* currNode, *nextNode;
	currNode = head;

	int deg = 0;		
	while(currNode!=0){
		if(currNode->data->getId() == id){
			deg = currNode->data->getEx();
			break;
		}
		nextNode = currNode->next;
		currNode = nextNode;

	}
	return deg;
}	

int XnList::getLeadDeg() 
{
	return head->data->getEx();
}


XnList& XnList::operator+=(Xn* newVar)
{
	int flag = 1; //1 if new variable 0 if not
	int updateEx = 0;
	Node *currNode, *prevNode;
	Node* newNode = new Node;
	newNode->data = newVar;
	newNode->next = 0;

	currNode = head;
	prevNode = 0;
	
	while(currNode != 0) {
		if(*(newNode->data) < *(currNode->data) || *(newNode->data) == *(currNode->data) ){
	//		if(*(newNode->data) == *(currNode->data)){ //same exponent
			//	currNode->data->setId() += newNode->data->id;
	//			updateEx = newNode->data->getEx() + currNode->data->getEx();
	//			currNode->data->setEx(updateEx);
				
				
			//	flag = 0;
//			}
		break;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
/*
	if(flag == 0){ //don't add the variable to the list
	//	delete newNode->data;
	//	delete newNode;
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




int XnList::getSize() const 
{
	Node* currNode = head;
	int size = 0;
	
	while(currNode != 0) {
		currNode = currNode->next;
		size++;
	}
	return size;
}

Xn* XnList::operator[](int index)
{
	if(index < 0 || index > (getSize()-1)){
		return 0;
	} else {
		
		Node *currNode = head;
		
		for(int i=0;i<index;i++){
			currNode = currNode->next;
		}
		return currNode->data;	
	}
}

std::ostream& operator<<(std::ostream& output, XnList& xl){

	for(int i=0; i < xl.getSize() ; i++) {
		output << (*(xl[i]));
	}

	return output;
}











