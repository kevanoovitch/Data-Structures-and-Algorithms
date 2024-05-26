#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "OrderedList.hpp"
#include <stdexcept>

template <class T>
class PriorityQueue
{
private:
	// Ad
	OrderedList<T> Mylist;
public:
	PriorityQueue();
	~PriorityQueue() = default;
	PriorityQueue(const PriorityQueue &other) = delete;
	PriorityQueue& operator=(const PriorityQueue &other) = delete;
	
	void enqueue(const T &element);
	T dequeue();
	T peek() const;
	bool is_empty() const;
	int size() const;
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{

}
template <class T>
void PriorityQueue<T>::enqueue(const T& element)
{

	//orded list makes sure it gets placed in correct position.
	Mylist.add(element);

}
template <class T>
T PriorityQueue<T>::dequeue()
{
	if (this->is_empty() == true)
	{
		throw std::runtime_error{ "dequeue() called on empty" };
	}
	return Mylist.removeFirst();
	
}
template <class T>
T PriorityQueue<T>::peek() const
{
	if (this->is_empty() == true)
	{
		throw std::runtime_error{ "Peek() called on empty" };
	}

	return Mylist.first();;
}
template <class T>
bool PriorityQueue<T>::is_empty() const
{
	if (Mylist.is_empty() == true)
	{
		return true;
	}
	return false;
}
template <class T>
int PriorityQueue<T>::size() const
{

	return Mylist.size();
}

#endif