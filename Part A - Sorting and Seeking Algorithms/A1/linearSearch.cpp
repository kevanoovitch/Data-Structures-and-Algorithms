#include <iostream>

int LinearSearch(int arr[], int target, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int MyArray[] = {53, 12, 8, 77, 5, 38, 72, 121, 1};
    int nrOfElements = sizeof(MyArray) / sizeof(MyArray[0]);
    std::cout << "index of target value: " << LinearSearch(MyArray, 12, nrOfElements) << std::endl;
}
