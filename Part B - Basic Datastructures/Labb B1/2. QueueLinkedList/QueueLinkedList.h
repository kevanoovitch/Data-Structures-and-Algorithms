#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>

/*
throw exception if dequeue() or peek() is excuted when queue is empty

for example in dequeue():

throw std::runtime_error("calling dequeue() on Empty queue")

if the queue is empty
*/

template <typename T>
class Queue
{
private:
	// inner class only accessible within Queue
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T data, Node* next = nullptr)
			: data(data), next(next) {}
	};
	Node* head;
	Node* tail;
public:
	Queue();
	virtual ~Queue();
	Queue(const Queue& other) = delete;
	Queue& operator=(const Queue& other) = delete;
	void enqueue(const T& element);
	T dequeue();
	const T& peek() const;
	bool is_empty() const;
};

#endif

//template<typename T>
//inline Queue<T>::Queue() : head(nullptr), tail(nullptr) {}
//
//template<typename T>
//inline Queue<T>::~Queue()
//{
//	//walk though list get the point to next then delete current
//	Node* walker = this->head;
//	while (walker != nullptr)
//	{
//		Node* nextTmp = walker->next;
//		delete walker;
//		walker = nextTmp;
//	}
//}
//
//template<typename T>
//inline void Queue<T>::enqueue(const T& element)
//{
//	// create a new node 
//	Node* newNode = new Node(element);
//		//if empty make head also point to new node
//	if (this->is_empty())
//	{
//		this->head = newNode;
//		this->tail = newNode;
//		}
//	else
//	{
//		//else make tail point to new node
//		this->tail->next = newNode; //tail.next points to nullptr
//		this->tail = newNode; //tail point to the new element (new is new last)
//	}
//		
//}
//
//template<typename T>
//inline T Queue<T>::dequeue()
//{
//	//remove the element that head points too, return the element value and then modify head ptr
//
//	if (!this->is_empty())
//	{
//		Node* tmp = this->head; // Store the old head node
//
//		this->head = this->head->next; //new head is the second to first element
//
//		T returnVal = tmp->data; // Get the data from the old head node
//		
//
//		if (this->head == nullptr) {  // If the head is now nullptr, the queue is empty
//			this->tail = nullptr;    // Set tail to nullptr as well because the queue is empty
//		}
//
//		delete tmp;        // Delete the head node
//
//		return returnVal;  // Return the data from the old head node
//	}
//	else
//	{
//		throw std::runtime_error("calling dequeue() on an empty queue");
//	}
//
//}
//
//template<typename T>
//inline const T& Queue<T>::peek() const
//{
//	if (!this->is_empty())
//	{
//		return this->head->data;
//	}
//	else
//	{
//		throw std::runtime_error{ "calling peek() on Empty queue" };
//	}
//
//}
//
//template<typename T>
//inline bool Queue<T>::is_empty() const
//{
//	if (this->head == nullptr)
//	{
//		//if there are no next in queue the queue has to be empty (right?)
//		return true;
//	}
//	return false;
//}
