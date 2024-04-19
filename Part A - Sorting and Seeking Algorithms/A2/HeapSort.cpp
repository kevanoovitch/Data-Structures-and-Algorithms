#include <iostream>

void ArrayPrinter(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << Arr[i] << ", ";
    }
    std::cout << std::endl;
}

template <class T>
void Heapify(T elements[], int k, int nrOfElements)
{
    int parent = elements[k];
    int childL = 0;
    int childR = 0;
    int childLIndex = -1;
    int largest = 0; // Stores index value of largest child

    int L = 2 * k + 1;
    int R = 2 * k + 2;
    if (L < nrOfElements) // checks if there is a left child eg. any children
    {
        childL = elements[L];
        childLIndex = L;

        if (R < nrOfElements) // checks if it also has a right child
        {
            childR = elements[R];
        }
    }

    if (childLIndex != -1) // if children exist
    {

        // Checks which child is largest
        if (childL > childR)
        {
            largest = L;
        }
        else
        {
            largest = R;
        }

        if (elements[largest] > parent)
        {
            std::swap(elements[k], elements[largest]);
            Heapify(elements, largest, nrOfElements);
        }
    }
}

template <class T>
void Heapsort(T elements[], int nrOfElements)
{
    for (int i = (nrOfElements / 2) - 1; i > 0; i--)
    {
        Heapify(elements, i, nrOfElements);
    }

    ArrayPrinter(elements, 10);

    for (int j = nrOfElements - 1; j > 0; j--)
    {
        // J is the last element and thus the first unsorted element?

        std::swap(elements[0], elements[j]);
        Heapify(elements, 0, j);
        // ArrayPrinter(elements, 10);
    }
}

int main()
{
    int arr[10] = {9, 7, 5, 3, 1, 8, 6, 4, 2, 0};

    Heapsort(arr, 9);
    ArrayPrinter(arr, 10);
    return 0;
}