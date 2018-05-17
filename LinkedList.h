#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
class LinkedList
{
	template <class U> 
	friend std::ostream& operator << (std::ostream&, LinkedList<U>&); //prob better ways to do this	
	
	class Node
	{
		friend class LinkedList;
		private:
			T*	  data;
			Node* next;
	};
	
	public:
		LinkedList();
		~LinkedList();
		void copyFrom(const LinkedList<T>&);
		void deleteNodes();
		LinkedList(const LinkedList<T>&);
		LinkedList& operator=(const LinkedList<T>&);
		LinkedList& operator+=(T*);
		LinkedList& operator-=(T*);
		T* operator[](int);
		int getSize() const;	
		
	private:
		Node* head;

};

template <class T>
LinkedList<T>::LinkedList() : head(0) 
{
	std::cout << "ll ctor" << std::endl;
}

template <class T>
LinkedList<T>::~LinkedList() 
{
	std::cout << "ll dtor" << std::endl;
	deleteNodes();
}

/*
NTBRW
*/

template <class T>
void LinkedList<T>::deleteNodes(){
	Node* currNode, *nextNode;
	currNode = head;

	
	while(currNode != 0){
		nextNode = currNode->next;
		delete currNode->data;		
		delete currNode;
		currNode = nextNode;
	}


} 

template <class T>
void LinkedList<T>::copyFrom(const LinkedList<T>& cpList)
{	
	std::cout << "copy called? " << std::endl;
	Node* cpCurrNode;
	cpCurrNode = cpList.head;	
	head = 0;
	while(cpCurrNode !=0){
		*this+=cpCurrNode->data;
		cpCurrNode = cpCurrNode->next;
		}
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& cpList) 
{	
	copyFrom(cpList);
}
/*
NTBRW
*/


template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
{
	//check for self assignment
	if(this == &rhs){
		return *this;
	}
	std::cout << "dtor in ass" << std::endl;

	//free old mememory

	deleteNodes();


	copyFrom(rhs);
	return *this;	
	

}





template <class T>
LinkedList<T>& LinkedList<T>::operator+=(T* newVar)
{
	Node* currNode, *prevNode;
	Node* newNode = new Node;
	newNode->data = newVar;
	newNode->next = 0;
	
	currNode = head;
	prevNode = 0;

	while(currNode != 0){
		if(*(newNode->data) > *(currNode->data)){
			break;	
		}
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
	
	return *this;
}


template <class T>
LinkedList<T>& LinkedList<T>::operator-=(T* a)
{
	Node* currNode, *prevNode;

	currNode = head;
	prevNode = 0;

	while (currNode != 0) {
		if (currNode->data == a)
			break;
		prevNode = currNode;
		currNode = currNode->next;
	}
	
	if (currNode == 0) {
		return *this;
	}
	if (prevNode == 0) {
		head = currNode->next;
	}
	else { 
		prevNode->next = currNode->next;
	}
	delete currNode->data;
	delete currNode;
	
	return *this;
}

template <class T>
T* LinkedList<T>::operator[](int index)
{
	if(index < 0 || index > (getSize() -1)){
		return 0;
	}
		
	Node* currNode = head;
	
	for(int i=0;i<index;i++){
		currNode =currNode->next;
	}

	return currNode->data;
	
}

template <class T>
int LinkedList<T>::getSize() const
{
	Node* currNode = head;
	int size = 0;
	
	while(currNode != 0){
		size++;
		currNode = currNode->next;
	}
	return size;
}

template <class T>
std::ostream& operator<<(std::ostream& output, LinkedList<T>& lk)
{
	for(int i=0; i < lk.getSize(); i++) {
		output << (*(lk[i]));
	}
	return output;
}



#endif
