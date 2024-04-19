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
int HoarePartition(T elements[], int start, int end)
{
    T pivotVal = elements[start];
    int Index = start;

    int l = start; // left index
    int r = end;   // right index

    while (true)
    {

        while (elements[l] < pivotVal && l < r) // Counter left -> right find value bigger then pivot val
        {
            l++;
        }

        while (elements[r] > pivotVal && r > l) // counter from right to left, find val smaller than pivot val
        {
            r--;
        }

        if (l >= r) // Values found that are not in the right place
        {
            return l;
        }

        std::swap(elements[l], elements[r]);
    }
}

template <class T>
void QuicksortHoareRec(T elements[], int start, int end)
{
    if (start < end)
    {
        int pivot = HoarePartition(elements, start, end);
        QuicksortHoareRec(elements, start, pivot);
        QuicksortHoareRec(elements, pivot + 1, end);
    }
}

template <class T>
void QuicksortHoare(T elements[], int nrOfElements)
{
    QuicksortHoareRec(elements, 0, nrOfElements - 1);
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    QuicksortHoare(arr, 10);
    ArrayPrinter(arr, 10);
    return 0;
}