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
		LinkedList(const LinkedList&);
		LinkedList& operator=(const LinkedList&);
		LinkedList& operator+=(T*);
		//LinkedList& operator-=(T*);
		T* operator[](int);
		int getSize() const;	
		
	private:
		Node* head;

};

template <class T>
LinkedList<T>::LinkedList() : head(0) {}

template <class T>
LinkedList<T>::~LinkedList() 
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
LinkedList<T>::LinkedList(const LinkedList& cpList) 
{	
	Node *currNode, *cpCurrNode, *newNode;
	currNode = head;
	cpCurrNode = cpList.head;
		
	if(cpCurrNode == 0){
		head = 0;
	}
	else{
		head->data = cpCurrNode->data;
		cpCurrNode = cpCurrNode->next;	
	}
	
		
	
	while(cpCurrNode != 0){
		newNode = new Node;
		newNode->data = cpCurrNode->data;
		currNode->next = newNode;
		currNode = newNode;
		cpCurrNode = cpCurrNode->next;
	}
}


template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
{
	T temp = rhs;
	head = temp.head;
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
