#include <iostream>
#include <vector>

void ArrayPrinter(int Arr[], int n, std::string type)
{
    std::cout << "<----- " << type << "----->" << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << Arr[i] << ", ";
    }
    std::cout << std::endl;
}

void CountingSort(int elements[], int nrOfElements)
{
    //Translation for codecrade because I am lazy
    int* A = elements;
    int nrOf = nrOfElements;



    //find the largest value in A (call it k)

    int k = 0;
    for (int i = 0; i < nrOf; i++)
    {
        if (A[i] > k)
        {
            k = A[i];
        }
    }

   
    //Create arr B which has size k + 1, where each element is 0

    int* B = new int[k + 1]{ 0 };

    //Count form A how many key values you have and put the result in B

    for (int i = 0; i < nrOf; i++)
    {
        int keyValA = A[i];

        B[keyValA]++;
    }

    ArrayPrinter(B, k + 1, "Debug");

    // Makes it into a prefix array
    
    for (int i = 1; i < k+1; i++)
    {
        B[i] = B[i - 1] + B[i];
    }

    ArrayPrinter(B, k + 1, "After summary");

    //Create C which has size nrOf (same size as A)

    int* C = new int[nrOf] {NULL};

    //Ittrate backwards from A and put in the correct position of C
    
    for (int i = nrOf; i > 0; i--)
    {
        int indexC = B[A[i]];

        C[indexC - 1] = A[i];
    }




    delete[] C;
    delete[] B;
}

int main()
{
   int TestArray[7] = {4, 2, 2, 8, 3, 3, 1};

    CountingSort(TestArray, 7);
    ArrayPrinter(TestArray, 7, "Sorted With Counting Sort");
    
}