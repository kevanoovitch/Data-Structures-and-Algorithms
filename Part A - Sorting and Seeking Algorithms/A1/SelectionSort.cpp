#include <iostream>

void swap(int Arr[], int index1, int index2)
{
    int temp = Arr[index1];
    Arr[index1] = Arr[index2];
    Arr[index2] = temp;
}

void SelectionSort(int Arr[], int n)
{
    int count1 = 0;
    int count2 = 0;
    int SmallestIndex = 0;
    for (int j = 0; j < n - 1;)
    {

        SmallestIndex = j;
        for (int i = j + 1; i < n; i++) // Is there anything that is smaller in the rest of the array?
        {

            if (Arr[i] < Arr[SmallestIndex]) // current element is smaller
            {
                SmallestIndex = i;
            }

            count2++;
        }
        // whole array checcked time for swap
        swap(Arr, SmallestIndex, j);
        j++;
        count1++;
    }

    std::cout << "for loop1 count: " << count1 << std::endl;
    std::cout << "for loop2 count: " << count2 << std::endl;
}

int main()
{
    /* code */
    int MyArray[] = {9, 7, 5, 3, 1, 8, 6, 4, 2, 0};
    int nrOfElements = sizeof(MyArray) / sizeof(MyArray[0]);

    SelectionSort(MyArray, nrOfElements);

    for (int i = 0; i < nrOfElements; i++)
    {
        std::cout << MyArray[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}
