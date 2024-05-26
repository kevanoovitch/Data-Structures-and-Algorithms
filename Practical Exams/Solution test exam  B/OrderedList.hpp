#ifndef ORDEREDLIST_HPP
#define ORDEREDLIST_HPP

#include <stdexcept>
#include <iostream>

template <class T>
class OrderedList
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node(const T &data, Node* next = nullptr)
			: data(data), next(next) {}
	};
	Node* front;
public:
	OrderedList();
	~OrderedList();
	OrderedList(const OrderedList &other) = delete;
	OrderedList& operator=(const OrderedList &other) = delete;

	int size() const;
    bool is_empty() const;
    void add(const T& element);
    T removeAt(int index);
    T removeFirst();
    T removeLast();
    T getAt(int index) const;
    T first() const;
    T last() const;
};

template <class T>
OrderedList<T>::OrderedList()
{
	this->front = nullptr;
}
template <class T>
OrderedList<T>::~OrderedList()
{
	Node *walker = this->front;
	while (walker != nullptr)
	{
		this->front = walker->next;
		delete walker;
		walker = this->front;
	}
}
template <class T>
int OrderedList<T>::size() const
{

	if (this->is_empty() == true)
	{
		throw std::runtime_error{ "E" };
	}

	Node* walker = this->front;
	int count = 1;

	while (walker->next != nullptr)
	{
		walker = walker->next;
		count += 1;
	}
	return count;
}
template <class T>
bool OrderedList<T>::is_empty() const
{
	if (this->front == nullptr)
	{
		return true;
	}
	return false;
}
template <class T>
void OrderedList<T>::add(const T& element)
{
	Node* NewNode = new Node(element);

	// om den är tom ändra front pekare
	if (this->front == nullptr)
	{
		this->front = NewNode;
		return;
	}
	// add new node in the correct positon (growing sequence)
	

	if (this->front->data >= NewNode->data)
	{
		//a special case where new elem is smaller then the first element
		NewNode->next = front;
		this->front = NewNode;
		return;
		
	}
	Node* walker = this->front;

	while (walker->next != nullptr)
	{
		
		if (walker->next->data >= NewNode->data )
		{

			//insert in the right place, Equal val placed before equal existing equal values.
			NewNode->next = walker->next;
			walker->next = NewNode;
			return;
		}
		walker = walker->next;
	}

	walker->next = NewNode;
}
template <class T>
T OrderedList<T>::removeAt(int index)
{
	if (this->is_empty() == true)
	{
		throw std::runtime_error{ "E" };
	}

	/*if (this->size() < index-1)
	{
		throw std::runtime_error{ "Ehm index is out of bounds man!" };
	}*/

	if (index == 0)
	{
		//spec case when only one element exist or first element is going to be removed
		return this->removeFirst();

	}

	// --- new diffrent implementation ----

	Node* walker = this->front;
	Node* prev = nullptr;
	int currentIndex = 0;
	while (walker != nullptr && index != currentIndex)
	{
		prev = walker;
		walker = walker->next;
		currentIndex += 1;
	}

	if (walker == nullptr) {
		throw std::runtime_error("Index is out of bounds");
	}

	T temp = walker->data;
	prev->next = walker->next;
	delete walker;
	
	return temp;
}
template <class T>
T OrderedList<T>::removeFirst()
{
	if (this->front == nullptr)
	{
		throw std::runtime_error{ "EE" };
	}

	Node* toDelete = front;
	T temp = toDelete->data;
	this->front = this->front->next;
	delete toDelete;
	return temp;
}
template <class T>
T OrderedList<T>::removeLast()
{
	if (this->is_empty() == true)
	{
		throw std::runtime_error{ "E!" };
	}


	if (this->front->next == nullptr)
	{
		//SPEC case with only one element
		T temp = this->front->data;
		delete this->front;
		this->front = nullptr;
		return temp;
	}

	Node* walker = this->front;
	Node* prev = nullptr;

	while (walker->next != nullptr)
	{
		prev = walker;
		walker = walker->next;
		
	}

	
	T temp = walker->data;
	delete walker;
	prev->next = nullptr;
	return temp;
}
template <class T>
T OrderedList<T>::getAt(int index) const
{
	if (this->is_empty() == true)
	{
		throw std::runtime_error{ "Exception on getAt!" };
	}

	if (index < 0 || index >= this->size())
	{
		throw std::runtime_error{ "Exception on getAt!" };
	}

	Node* walker = this->front;
	int currentIndex = 0;
	while (currentIndex != index )
	{
		walker = walker->next;
		currentIndex += 1;
	}

	return walker->data;
}
template <class T>
T OrderedList<T>::first() const
{
	if (this->front == nullptr)
	{
		throw std::runtime_error{ "EE" };
	}


	return this->front->data;
}
template <class T>
T OrderedList<T>::last() const
{
	if (this->is_empty() == true)
	{
		throw std::runtime_error{ "!" };
	}

	Node* walker = this->front;

	while (walker->next != nullptr)
	{
		walker = walker->next;
	}
	return walker->data;
}

#endif