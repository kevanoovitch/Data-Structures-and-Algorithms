#include <vector>
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
void Merge(T elements[], int start, int mid, int end)
{
    int leftNrOfElements = mid - start + 1;
    int rightNrOfElements = end - mid;
    T *left = new T[leftNrOfElements];
    T *right = new T[rightNrOfElements];

    for (int i = 0; i < leftNrOfElements; ++i)
        left[i] = elements[start + i];
    for (int i = 0; i < rightNrOfElements; ++i)
        right[i] = elements[mid + 1 + i];

    int i = start, j = 0, k = 0;
    while (j < leftNrOfElements && k < rightNrOfElements)
    {
        if (left[j] <= right[k])
        {
            elements[i] = left[j];
            ++j;
        }
        else
        {
            elements[i] = right[k];
            ++k;
        }
        ++i;
    }

    while (j < leftNrOfElements)
    {
        elements[i] = left[j];
        ++j;
        ++i;
    }
    while (k < rightNrOfElements)
    {
        elements[i] = right[k];
        ++k;
        ++i;
    }
    ArrayPrinter(elements, end);
}

int MergesortRec(int elements[], int StartIndex, int EndIndex)
{

    if (StartIndex < EndIndex) // There is more than one value in the sequence
    {
        int MiddleIndex = (StartIndex + EndIndex) / 2;
        MergesortRec(elements, StartIndex, MiddleIndex);   // Left part
        MergesortRec(elements, MiddleIndex + 1, EndIndex); // Right Part
        Merge(elements, StartIndex, MiddleIndex, EndIndex);
    }

    return elements[StartIndex];
}

template <class T>
void Mergesort(T elements[], int nrOfElements)
{

    MergesortRec(elements, 0, nrOfElements);
}

int main()
{

    int *DynamicArr = new int[10]{5, 3, 9, 8, 7, 2, 4, 1, 6, 5};

    Mergesort(DynamicArr, 9);

    ArrayPrinter(DynamicArr, 10);

    delete[] DynamicArr;
    return 0;
}
