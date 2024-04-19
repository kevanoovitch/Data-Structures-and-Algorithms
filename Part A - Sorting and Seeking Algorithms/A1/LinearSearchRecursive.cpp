#include <iostream>

int LinearSearchRecursiveHelper(int arr[], int target, int index, int n)
{
    // Base case: if the index reaches the size of the array, the target is not found
    if (index == n)
    {
        return -1;
    }
    // If the current element is the target, return the current index
    if (arr[index] == target)
    {
        return index;
    }
    // Otherwise, search in the rest of the array
    return LinearSearchRecursiveHelper(arr, target, index + 1, n);
}

// Wrapper function for the recursive linear search
int LinearSearchRecursive(int arr[], int target, int n)
{
    return LinearSearchRecursiveHelper(arr, target, 0, n);
}

int main()
{
    int MyArray[] = {53, 12, 8, 77, 5, 38, 72, 121, 1};
    int nrOfElements = sizeof(MyArray) / sizeof(MyArray[0]);
    std::cout << "index of target value: " << LinearSearchRecursive(MyArray, 12, nrOfElements) << std::endl;
}
