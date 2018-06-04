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
		void copyFrom(const LinkedList<T>&); // used for copy constructor
		void deleteNodes(); //used for destructor
		LinkedList(const LinkedList<T>&); //copy constructor
		LinkedList& operator=(const LinkedList<T>&); //assignment operator
		LinkedList& operator+=(T*); //add to the list
		LinkedList& operator-=(T*); //delete an element in a list
		T* operator[](int);  //get element in list
		int getSize() const; //return the number of elements in the list
		
	private:
		Node* head;

};

template <class T>
LinkedList<T>::LinkedList() : head(0) {}


template <class T>
LinkedList<T>::~LinkedList() 
{
	deleteNodes();
}

template <class T>
void LinkedList<T>::deleteNodes()
{
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
	Node* cpCurrNode;
	cpCurrNode = cpList.head;	
	head = 0;
	while(cpCurrNode !=0){
		T* newData = new T();
		*newData = *cpCurrNode->data;
		*this+=newData;
		cpCurrNode = cpCurrNode->next;
		}
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& cpList) 
{	
	copyFrom(cpList);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
{
	std::cout << "assignment called" << std::endl;
	//check for self assignment
	if(this == &rhs){
		return *this;
	}

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
