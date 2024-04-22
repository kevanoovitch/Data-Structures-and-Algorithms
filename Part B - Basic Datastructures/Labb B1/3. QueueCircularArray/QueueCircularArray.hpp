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
	T* elements;
	int currentCapacity;
	int head;
	int tail;
	void expand();
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



template<typename T>
inline void Queue<T>::expand()
{
	// make a new capacity
	int newCap = (this->currentCapacity + 1) * 2;

	//make a new array with the new capacity 
	T* newArray = new T[newCap];

	//copy old data to new larger array
	for (int i = 0; i < this->currentCapacity; i++)
	{
		newArray[i] = this->elements[i];
	}
	//delete old and smaller array
	delete[] this->elements;

	this->currentCapacity = newCap;
	this->elements = newArray;
	
}

template<typename T>
inline Queue<T>::Queue() 
{
	this->currentCapacity = 1;
	this->head = -1;
	this->tail = -1;
	
	this->elements = new T[currentCapacity];
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete[] this->elements;
}

template<typename T>
inline void Queue<T>::enqueue(const T& element)
{
	if (this->is_empty())
	{
		this->head = 0;
		this->tail = 0;
		this->elements[this->head] = element;
	}
	else
	{

		if (this->tail + 1 >= this->currentCapacity) //if queue is full
		{
			this->expand(); //else make room
		}

		if (this->tail == this->currentCapacity - 1 && this->head != 0)
		{

			this->tail = 0;
			this->elements[this->tail] = element;
			//this->elements[tail++] = element; //++tail represents next
		}
		else
		{
			this->elements[++this->tail] = element;
		}
	}

	
}

template<typename T>
inline T Queue<T>::dequeue()
{
	if (this->is_empty()) {
		throw std::runtime_error{ "calling dequeue() on empty queue" };
	}

	T tmp = this->elements[this->head];  // Store the dequeued value

	if (this->head == this->tail) {
		// Queue becomes empty
		this->head = -1;
		this->tail = -1;
	}
	else if (this->head == this->currentCapacity - 1) {
		// Wrap around in a circular queue
		this->head = 0;
	}
	else {
		this->head++;  // Move `head` to the next position
	}

	return tmp;  // Return the dequeued value
}


template<typename T>
inline const T& Queue<T>::peek() const
{
	if (!this->is_empty())
	{
		return this->elements[this->head];
	}
	else
	{
		throw std::runtime_error{ "calling peek() on Empty queue" };
	}
}

template<typename T>
inline bool Queue<T>::is_empty() const
{
	if (this->head == -1) //-1 represents empty or nullptr in diffrecnt variant
	{
		return true;
	}
	return false;
}

#endif