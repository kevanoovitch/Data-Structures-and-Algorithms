#include <iostream>
#include "ExaminationA.hpp"
void ArrayPrinter(int arr[], int n, std::string type)
{
	std::cout << "Sorted with " << type << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ", ";
	
	}
	std::cout << std::endl;
}

int main()
{


	int MyArray[10]{ 9,7,5,6,8,4,9,2,4,5};
	insertionSort(MyArray, 10);
	ArrayPrinter(MyArray, 10, "InsertSort");

	std::cout << "nr 5 found at: " << binarySearch(MyArray, 10, 5) << std::endl;
	
}