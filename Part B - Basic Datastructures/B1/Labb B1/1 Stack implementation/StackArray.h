#pragma once
#ifndef STACK_H
#define STACK_H
#include <stdexcept>

/*
throw exception if pop() or peek() is excuted when stack is empty

for example in pop():

throw std::runtime_error("calling pop() on Empty stack")

if the stack is empty
*/

template <typename T>
class Stack
{
private:
	T* elements;
	int currentCapacity;
	int top;
	void expand();
public:
	Stack(int initialCapacity = 10);
	virtual ~Stack();
	Stack(const Stack& other) = delete;
	Stack& operator=(const Stack& other) = delete;
	void push(const T& element);
	T pop();
	const T& peek() const;
	bool is_empty() const;
};



#endif

template<typename T>
inline void Stack<T>::expand()
{
	int newCap = (this->currentCapacity * 2) + 1;

	T* NewArr = new T[newCap];

	for (int i = 0; i < this->currentCapacity; i++)
	{
		NewArr[i] = this->elements[i];
	}

	delete[] elements;

	this->elements = NewArr;
}

template<typename T>
inline Stack<T>::Stack(int initialCapacity)
{
	this->currentCapacity = initialCapacity;
	this->elements = new T[initialCapacity];
	this->top = 0;
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] this->elements;
}

template<typename T>
inline void Stack<T>::push(const T& element)
{
	if (this->currentCapacity == this->top)
	{
		expand();
	}
	this->elements[this->top++] = element;
}

template<typename T>
inline T Stack<T>::pop()
{
	if (! this->is_empty())
	{
		return this->elements[--this->top];
	}
	throw std::runtime_error{ "Error: pop called on empty stack" };
}

template<typename T>
inline const T& Stack<T>::peek() const
{
	if (!this->is_empty())
	{
		return this->elements[this->top - 1];
	}
	throw std::runtime_error{ "Error: peek called on empty stack" };
	
}

template<typename T>
inline bool Stack<T>::is_empty() const
{
	if (this->top > 0)
	{
		return false;
	}
	return true;
}
