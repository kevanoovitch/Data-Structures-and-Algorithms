#include <iostream>
#include <vector>

int binarySearch(int Arr[], int input, int high)
{
    int low = 0;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (input <= Arr[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low; // This is the correct position for 'input'.
}

void insertSort(int Arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = Arr[i];
        int WhereToPut = binarySearch(Arr, key, i);

        // Move elements of Arr[0..i-1], that are greater than key, to one position ahead of their current position
        for (int j = i - 1; j >= WhereToPut; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[WhereToPut] = key;
    }
}

int main()
{
    int MyArr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(MyArr) / sizeof(MyArr[0]);

    insertSort(MyArr, n);

    // Print sorted array
    for (int i = 0; i < n; i++)
    {
        std::cout << MyArr[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}