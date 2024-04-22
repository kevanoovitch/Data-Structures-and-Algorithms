#pragma once
#ifndef ORDEREDLIST_HPP
#define ORDEREDLIST_HPP

#include <stdexcept>

template <class T>
class OrderedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    int num_elements;

public:
    OrderedList();
    ~OrderedList();
    OrderedList(const OrderedList& other) = delete;
    OrderedList& operator=(const OrderedList& other) = delete;

    int size() const;
    bool is_empty() const;
    void add(const T& element);
    T remove(const T& element);
    T removeAt(int index);
    T removeFirst();
    T removeLast();
    T get(const T& element) const;
    T first() const;
    T last() const;
};

#endif

template <class T>
OrderedList<T>::OrderedList() :
    front(nullptr), num_elements(0)
{

}
template <class T>
OrderedList<T>::~OrderedList() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}
template <class T>
int OrderedList<T>::size() const {
    // Returns size of OrderedList

    Node* walker = this->front;
    int counter = 0;
    while (walker != nullptr)
    {
        walker = walker->next;
        counter++;
    }
    return counter;

    return -1;
}
template <class T>
bool OrderedList<T>::is_empty() const {
    // Returns if OrderedList is empty or now
    if (this->num_elements == 0)
    {
        return true;
    }


    return false;
}
template <class T>
void OrderedList<T>::add(const T& element) {
    // Adds element to the OrderedList in its correct place

    // Create a node that points to null
    Node* NewNode = new Node(element); 

    if (this->front == nullptr || element < front->data)
    {
        NewNode->next = front;
        front = NewNode;
        
    }
    else
    {
        Node* walker = front;
        while (walker->next != nullptr && walker->next->data < element)
        {
            walker = walker->next;
        }
        NewNode->next = walker->next;
        walker->next = NewNode;
       
    }
    this->num_elements++;

  
   
}
template <class T>
T OrderedList<T>::remove(const T& element) {
    // Removes and returns specific element from the OrderedList

    //throw exception for empty array 
    if (!this->is_empty())
    {
        //itterate with walker to find the data you want to remove
        Node* walker = front;

        for (size_t i = 0; i < --this->size(); i++)
        {
            walker = walker->next;
        }
        
        Node* tmp = walker->next;
        walker.next = tmp->next;
        return T(tmp->data)
    }
    else
    {
        throw std::runtime_error{ "Remove called on an empty list" };
    }
    
}
template <class T>
T OrderedList<T>::removeAt(int index) {
    // Removes and returns element at specific index from the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::removeFirst() {
    // Removes and returns the first element from the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::removeLast() {
    // Removes and returns the last element from the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::get(const T& element) const {
    // Returns a specific element in the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::first() const {
    // Returns the first element in the OrderedList
    return T();
}
template <class T>
T OrderedList<T>::last() const {
    // Returns the last element in the OrderedList

    //thows excpetion if list is empty
    if (!this->is_empty())
    {
        Node* walker = this->front;

        while (walker->next != nullptr)
        {
            walker = walker->next;
        }
        return walker->data;
    }
    //else throw exception 
    throw std::runtime_error{ "Stack is empty when looking at last element" };
    
}