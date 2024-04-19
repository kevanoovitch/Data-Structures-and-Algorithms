#include <iostream>

int binarySearch(int Arr[], int target, int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (high + low) / 2;

        if (Arr[mid] == target)
        {
            // Target found
            return mid;
        }

        else if (Arr[mid] != target)
        {
            if (target < Arr[mid])
            {
                // Choose Left
                high = mid - 1;
            }
            else
            {
                // Choose right
                low = mid + 1;
            }
        }
    }
    return -1; // Target not found
}

int main()
{
    int MyArray[] = {1, 5, 8, 12, 38, 53, 72, 77, 99};
    int MyArraySize = sizeof(MyArray) / sizeof(MyArray[0]);
    /* code */

    std::cout << "index of target value: " << binarySearch(MyArray, 12, MyArraySize) << std::endl;

    return 0;
}
