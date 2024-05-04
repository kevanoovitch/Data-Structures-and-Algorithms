#ifndef INDEXEDLIST_HPP
#define INDEXEDLIST_HPP

#include <stdexcept>

template <class T>
class IndexedList {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(T data = nullptr) : data(data), next(nullptr) {}
    };
    Node* front;
    int num_elements;
public:
    IndexedList();
    ~IndexedList();
    IndexedList(const IndexedList& other) = delete;
    IndexedList& operator=(const IndexedList& other) = delete;

    int size() const;
    bool is_empty() const;
    T getAt(int index) const;
    void addAt(int index, const T& element);
    T removeFirst();
    T removeAt(int index);
    T removeLast();
    T first() const;
    T last() const;
};



template<class T>
IndexedList<T>::IndexedList() :
    front(nullptr), num_elements(0)
{

}

template <class T>
IndexedList<T>::~IndexedList()
{
    while (this->front != nullptr)
    {
        Node* temp = this->front;
        this->front = this->front->next;
        delete temp;
    }
}

template <class T>
int IndexedList<T>::size() const {
    // Returns size of IndexedList



    return this->num_elements;
}

template <class T>
bool IndexedList<T>::is_empty() const {
    // Returns if empty or not

    if (this->num_elements == 0)
    {
        return true;
    }

    return false;
}

template <class T>
T IndexedList<T>::getAt(int index) const {
    // Returns element at index

    if (this->is_empty()) {
        throw std::runtime_error{ "Exception: getAt() called on an empty list" };
    }

    if (index >= 0 || index >= this->num_elements)
    {
        Node* walker = this->front;

        for (int i = 0; i < index; i++)
        {
            walker = walker->next;
        }
        return walker->data;
    }
    else
    {
        throw std::runtime_error{"Exception getAt() index value out of bounds"};
    }
    
}

template <class T>
void IndexedList<T>::addAt(int index, const T& element)
{
    // Adds element at an index

    if (index < 0 || index > this->num_elements)
    {
        throw std::runtime_error{ "Exception: Index out of bounds" };
    }


        Node* walker = this->front;
        Node* NewNode = new Node(element);

        if (index == 0)
        {
            NewNode->next = this->front; //new node points to a eventuall previus front node
            this->front = NewNode;
        }
        else if (index == this->num_elements)
        {
            if (this->front == nullptr)
            {
                this->front = NewNode;
            }
            else
            {
                while (walker->next != nullptr)
                {
                    walker = walker->next;
                }
                walker->next = NewNode;
            }
        }
        else
            {
                for (int i = 0; i < index - 1; i++) //walk to the node before 'inser node'
                {
                    walker = walker->next;
                }

                NewNode->next = walker->next;
                walker->next = NewNode;


            }
      
    this->num_elements++;
}

template <class T>
T IndexedList<T>::removeFirst() {
    // Removes first element in the IndexedList


    if (!this->is_empty())
    {
        Node* tmp = this->front;
        T tmpVal = this->front->data;
        this->front = this->front->next;

        delete tmp;
        this->num_elements--;
        return tmpVal;
    }
    
    else
    {
        throw std::runtime_error{ "Exception: reomveFirst() called on an empty array" };
    }

}

template <class T>
T IndexedList<T>::removeAt(int index) {
    // Removes element at specific index

    if (this->is_empty())
    {
        throw std::runtime_error{ "Exception: reomveAt() called on an empty array" };
    }

    if (index < 0 || index >= this->num_elements)
    {
        throw std::runtime_error{ "Exception RemoveAt() called with an invalid index" };
    }

    else
    {
        Node* walker = this->front;
        Node* walkerPrev = nullptr;

        if (index == 0) //Case for removing first node -> move front ptr and delete
        {
            T tmpVal = walker->data;
            this->front = walker->next;
            delete walker;
            this->num_elements--;
            return tmpVal;
        }

        for (int i = 0; i < index - 1; i++) //Iterate to the node before the one for deletion
        {
            walker = walker->next;
        }

        walkerPrev = walker; //the node before the one to delete
        walker = walker->next; //the one to be deleted
       
        T tmpVal = walker->data;
        walkerPrev->next = walker->next; //Moves pointer to "skip" the node to be deleted

        delete walker;

        this->num_elements--;
        return tmpVal;
    }
}

template <class T>
T IndexedList<T>::removeLast() {
    // Removes last element in the IndexedList

    if (this->is_empty())
    {
        throw std::runtime_error{ "Exception: reomveLast() called on an empty array" };
    }

    if (this->num_elements == 1) //spec case when only one element exists
    {
        Node* toRemove = this->front;
        T tmp = toRemove->data;
        this->front = nullptr;
        delete toRemove;
        this->num_elements--;
        return tmp;
    }

    Node* walker = this->front;

    for (int i = 0; i < this->num_elements-2; i++) //itterate to second to last
    {
        walker = walker->next;
    }

    Node* toRemove = walker->next;
    T tmpVal = toRemove->data;
    walker->next = nullptr;

    delete toRemove;

    this->num_elements--;

    return tmpVal;
    
}

template <class T>
T IndexedList<T>::first() const {
    // Returns the first element in the IndexedList
    if (this->is_empty())
    {
        throw std::runtime_error{ "Exception: first() called on an empty array" };
    }

    
    return this->front->data;
}

template <class T>
T IndexedList<T>::last() const {
    // Returns the last element in the IndexedList

    if (this->is_empty())
    {
        throw std::runtime_error{ "Exception: last() called on an empty array" };
    }

    Node* walker = this->front;

    while (walker->next != nullptr)
    {
        walker = walker->next;
    }

    return walker->data;
}

#endif