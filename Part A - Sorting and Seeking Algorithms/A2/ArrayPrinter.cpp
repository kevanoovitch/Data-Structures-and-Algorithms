#include <iostream>
void ArrayPrinter(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << Arr[i] << ", ";
    }
    std::cout << std::endl;
}