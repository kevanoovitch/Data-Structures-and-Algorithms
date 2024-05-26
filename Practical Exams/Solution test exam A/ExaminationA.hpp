#ifndef EXAMINATION_HPP
#define EXAMINATION_HPP
#include <utility>

const bool SELECTION_IMPLEMENTED = true;
const bool INSERTION_IMPLEMENTED = false;

template<typename T> 
void insertionSort(T arr[], int nrOf)
{

	for (int i = 1; i < nrOf; i++)
	{
		T key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = key;
	}
	
}

template<typename T> 
void selectionSort(T arr[], int nrOf)
{
	//Two for loops

	for (int i = 0; i < nrOf-1; i++)
	{
		int smallestIndex = i;
		for (int j = i + 1; j < nrOf; j++)
		{
			if (arr[j] < arr[smallestIndex])
			{
				smallestIndex = j;
			}
		}
		std::swap(arr[i], arr[smallestIndex]);
	}
} 

template<typename T> 
void merge(T arr[], int startIndex, int midIndex, int endIndex)
{
	//Define subarr left
	int sizeLeft = (midIndex - startIndex) + 1;
	T* subLeft = new T[sizeLeft];
	for (int i = 0; i < sizeLeft; i++)
	{
		subLeft[i] = arr[startIndex + i];
	}

	//define subarr right
	int sizeRight = (endIndex - midIndex);
	T* subRight = new T[sizeRight];
	for (int i = 0; i < sizeRight; i++)
	{
		subRight[i] = arr[(midIndex + 1) + i];
	}

	int indexLeft = 0;
	int indexRight = 0;
	int mainIndex = startIndex;
	//while loop the contest
	while (indexLeft < sizeLeft && indexRight < sizeRight)
	{
		if (subLeft[indexLeft] <= subRight[indexRight])
		{ 
			arr[mainIndex] = subLeft[indexLeft];
			indexLeft++;
		}
		else
		{
			arr[mainIndex] = subRight[indexRight];
			indexRight++;
		}
		mainIndex++;
	}

	//while looop the rest of left
	while (sizeLeft > indexLeft)
	{
		arr[mainIndex] = subLeft[indexLeft];
		indexLeft++;
		mainIndex++;
	}

	//while loop the rest of right

	while (sizeRight > indexRight)
	{
		arr[mainIndex] = subRight[indexRight];
		indexRight++;
		mainIndex++;
	}

	//clean up
	delete[] subRight;
	delete[] subLeft;
} 

template<typename T> 
void mergeSortRecursive(T arr[], int startIndex, int endIndex)
{
	if(startIndex < endIndex)
	{
		int midIndex = (startIndex+endIndex)/2;
		mergeSortRecursive(arr, startIndex, midIndex);
		mergeSortRecursive(arr, midIndex+1, endIndex);
		merge(arr, startIndex, midIndex, endIndex);
	}
} 
 
template<typename T> 
void mergeSort(T arr[], int nrOf)
{
	mergeSortRecursive(arr, 0, nrOf-1);
} 

template<typename T> 
int binarySearchRecursive(T arr[], int startIndex, int endIndex, T elem)
{
	//starting while loop
	while (endIndex >= startIndex)
	{
		//define mid
		int midIndex = (endIndex + startIndex) / 2;

			//check if mid is target
		if (arr[midIndex] == elem)
		{
			return midIndex;
		}

		// if elem is less than midVal choose left
		if (elem <= arr[midIndex])
		{
			return binarySearchRecursive(arr, startIndex, midIndex - 1, elem);
		}
		else
		{
			//else choose right
			return binarySearchRecursive(arr, midIndex + 1, endIndex, elem);
		}

		
	}

	
	return -1;
} 

template<typename T> 
int binarySearch(T arr[], int nrOf, T elem)
{
	return binarySearchRecursive(arr, 0, nrOf-1, elem);
} 


#endif //EXAMINATION_HPP