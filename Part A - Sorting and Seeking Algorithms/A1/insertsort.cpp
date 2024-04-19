#include <iostream>

void insertSort(int Arr[], int n)
{
    for (int i = 1; i < n; i++) // starts at second element
    {
        int key = Arr[i]; // Current value
        int j = i - 1;    // previous element
        while (j >= 0 && Arr[j] > key)
        {
            Arr[j + 1] = Arr[j];
            j = j - 1;
        }

        Arr[j + 1] = key;

        /* code */
    }
}

int main()
{

    int MyArr[] = {9, 7, 5, 3, 1, 8, 6, 4, 2, 0};
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