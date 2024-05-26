 #include "ExaminationA.hpp"
#include <iostream>

void ArrayPrinter(int Arr[], int n, std::string type)
{
    std::cout << "<----- " << type << "----->" << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << Arr[i] << ", ";
    }
    std::cout << std::endl;
}

int main()
{

    int MyArr[]{ 9, 7, 5, 3, 1, 8, 6, 4, 2, 0 };
    int MySortedArr[]{ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    insertionSort(MyArr, 10);
    ArrayPrinter(MyArr, 10, "Insert Sorted Array");

    selectionSort(MyArr, 10);
    ArrayPrinter(MyArr, 10, "Selection Sorted Array");

    mergeSort(MyArr, 10);
    ArrayPrinter(MyArr, 10, "Merge Sorted Array");

    binarySearch(MySortedArr, 10, 11);
    
    return 0;
} 