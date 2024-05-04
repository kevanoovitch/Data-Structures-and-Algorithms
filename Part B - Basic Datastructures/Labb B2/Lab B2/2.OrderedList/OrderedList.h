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

    //IF the list is empty
    if (this->is_empty())
    {
        this->front = NewNode;
        
    }
    //IF the list has only one element
    else if (this->num_elements == 1)
    {
        //is new element greater or lesser then exisiting element?

        if (front->data > element) //if new element is samller put before
        {
            NewNode->next = this->front;
            this->front = NewNode;
            
        }
        else 
        {
            //insert in the back

            this->front->next = NewNode;
        }
        
    }
    else
    {
        //itterate to the first node that is bigger than elem

        Node* walker = this->front; 
        Node* prev = nullptr;
        while (walker != nullptr)
        {
           if (element <= walker->data) 
            { 
              //found right position  
                break;
            }
           prev = walker;
            walker = walker->next; //traversal
        } 

        if (prev == nullptr)
        {
            // If previous is null, the new node becomes the front
            NewNode->next = this->front;
            this->front = NewNode;
        }
        else
        {
            // Otherwise, insert between previous and walker
            NewNode->next = walker;
            prev->next = NewNode;
        }
              
    }

    this->num_elements++; //In every case increase number of elements!

}
template <class T>
T OrderedList<T>::remove(const T& element) {
    // Removes and returns specific element from the OrderedList

    //throw exception for empty array 
    if (!this->is_empty())
    {
        
        Node* walker = this->front;

        //if first object is toRemove special case!
        if (this->front->data == element)
        {
            Node* toRemove = walker;
            this->front = walker->next;
            T toRemoveData = toRemove->data;

            delete toRemove; 

            this->num_elements--;
            return toRemoveData;

        }

        //Otherwise traverse the list
        while (walker->next != nullptr)
        {
          
            if (walker->next->data == element) //next element is the ToRemove
            {
                //element found stop traversing

                Node* toRemove = walker->next;
                walker->next = toRemove->next; // Adjust the links
                T toRemoveData = toRemove->data;
                delete toRemove;
                this->num_elements--;
                return toRemoveData; // Return the removed datas
            }
            walker = walker->next;
           
        }
        
     

     
        throw std::runtime_error{ "Element not in list" };
    }
    else
    {
        throw std::runtime_error{ "Remove called on an empty list" };
    }
    
}
template <class T>
T OrderedList<T>::removeAt(int index) {
    // Removes and returns element at specific index from the OrderedList

    if (!this->is_empty())
    {
        Node* walker = this->front;
        //[SPEC CASE] if it is the first element
        if (index == 0)
        {
            this->front = walker->next;
            Node* toRemove = walker;
            T Data = walker->data;

            this->num_elements--;
            delete toRemove;
            return Data;
        }
        else
        {
            //traverse to the node before the one with the correct index
            for (size_t i = 0; i < index-1; i++)
            {
                walker = walker->next;
            }

            Node* toRemove = walker->next;
            T Data = toRemove->data;
            this->num_elements--;
            walker->next = toRemove->next;
            delete toRemove;
            return Data;
        }
    }
    else
    {
        throw std::runtime_error{ "removeAt() called on empty list" };
    }
    
    return T();
}
template <class T>
T OrderedList<T>::removeFirst() {
    // Removes and returns the first element from the OrderedList

    if (!this->is_empty())
    {
        T FirstData = front->data;
        Node* toRemove = this->front;
        this->front = front->next;

        this->num_elements--;
        delete toRemove;
        return FirstData;
    }
    else
    {
        throw std::runtime_error{ "removeFirst() called on empty list" };
    }

   
}
template <class T>
T OrderedList<T>::removeLast() {
    // Removes and returns the last element from the OrderedList

    if (!this->is_empty())
    {



        Node* walker = this->front;

        if (this->num_elements == 1) // [SPEC CASE] if there is only one element
        {
            T returnData = this->front->data;
            delete this->front;
            this->front = nullptr;
            this->num_elements--;
            return returnData;
        }

        else
        {
            //Traverse until second to last
            for (int i = 1; i < this->num_elements - 1; i++)
            {
                walker = walker->next;
            }

            Node* toRemove = walker->next;
            T returnData = toRemove->data;

            this->num_elements--;
            walker->next = nullptr;

            delete toRemove;
            return returnData;
        }

       
    }
    else
    {
        throw std::runtime_error{ "removeLast() called on empty list" };
    }
    
    return T();
}
template <class T>
T OrderedList<T>::get(const T& element) const {
    // Returns a specific element in the OrderedList
    if (!this->is_empty())
    {
        Node* walker = this->front;
        for (int i = 0; i < this->num_elements; i++)
        {
            if (walker->data == element)
            {
                //found the element!
                return walker->data;
            }
            walker = walker->next;
        }
    }
    else
    {
        throw std::runtime_error{ "Get() called on empty list" };
    }
}
template <class T>
T OrderedList<T>::first() const {
    // Returns the first element in the OrderedList
    if (!this->is_empty())
    {
     
        return this->front->data;
    }
    //else throw exception 
    throw std::runtime_error{ "Stack is empty when looking at last element" };

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