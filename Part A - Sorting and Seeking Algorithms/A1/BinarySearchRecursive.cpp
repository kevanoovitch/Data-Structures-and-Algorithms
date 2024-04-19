#include <iostream>

int BinarySearchHelper(int Arr[], int target, int low, int high)
{
    int mid = (high + low) / 2;

    if (Arr[mid] != target)
    {
        if (target < Arr[mid])
        {
            // Choose Left
            high = mid - 1;
            return BinarySearchHelper(Arr, target, low, high);
        }
        else
        {
            // Choose right
            low = mid + 1;
            return BinarySearchHelper(Arr, target, low, high);
        }
    }

    else if (Arr[mid] == target)
    {
        // Target found
        return mid;
    }

    return -1; // Target not found
}

int BinarySearchRecursive(int Arr[], int target, int n)
{
    return BinarySearchHelper(Arr, target, 0, n - 1);
}

int main()
{
    int MyArray[] = {1, 5, 8, 12, 38, 53, 72, 77, 99};
    int MyArraySize = sizeof(MyArray) / sizeof(MyArray[0]);
    /* code */

    std::cout << "index of target value: " << BinarySearchRecursive(MyArray, 12, MyArraySize) << std::endl;

    return 0;
}
