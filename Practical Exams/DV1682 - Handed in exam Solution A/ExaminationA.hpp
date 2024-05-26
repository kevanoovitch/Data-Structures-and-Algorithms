const bool SELECTION_IMPLEMENTED = true;
const bool INSERTION_IMPLEMENTED = false;

#include <utility>

template<typename T> 
int binarySearch(T arr[], int nrOf, T elem)
{
	int leftIndex = 0;
	int rightIndex = nrOf - 1;
	
	while (leftIndex <= rightIndex)
	{
		//check for new mid
		int midIndex = (rightIndex + leftIndex) / 2;
		if (arr[midIndex] == elem)
		{
			//base case
			return midIndex;
		}

		if (elem < arr[midIndex])
		{
			// choose left
			
			rightIndex = midIndex-1; 

		}
		else
		{
			//choose right
			leftIndex = midIndex + 1;
			

		}
	}
	//base case if missing
	return -1;
}

template<typename T> 
void insertionSort(T arr[], int nrOf)
{
	//for loop starting on the second element
	for (int i = 1; i < nrOf; i++)
	{
		int j = i - 1; //the first and later previous element
		T key = arr[i]; //uses in the closing swap and comparison
		//for loop again and overwrite or while?
		while (j >= 0 && arr[j] > key) //while j is a valid index AND if current J val i lesser than key
		{
			arr[i + 1] = arr[j]; 
			j = j - 1;
		}
		//close the swap
		arr[i - 1] = key;


		//problem 9 7 5 becomes 7 7 9, switching key to arr[i+1] is a workaround and not correct for all cases
		
	}
	

	
}

template<typename T> 
void selectionSort(T arr[], int nrOf)
{
	for (int i = 0; i < nrOf-1; i++)
	{
		int smallestIndex = i;
		for (int j = i+1; j < nrOf; j++) //check "unsorted part" for a val smaller than current standing
		{
			if (arr[j] <= arr[smallestIndex])
			{
				smallestIndex = j;
			}
		}
		std::swap(arr[i], arr[smallestIndex]); //if something smaller was found then it will swap
	}
} 

template<typename T> 
void merge(T arr[], int startIndex, int midIndex, int endIndex)
{
	int leftNrOf = midIndex-startIndex+1;
	int rightNrOf = endIndex-midIndex;
	T* left = new T[leftNrOf];
	T* right = new T[rightNrOf];

	for(int i = 0; i < leftNrOf; ++i)
		left[i] = arr[startIndex+i];
	for(int i = 0; i < rightNrOf; ++i)
		right[i] = arr[midIndex+1+i];

	int i=startIndex,j=0,k=0;
	while(j < leftNrOf && k < rightNrOf)
	{
		if(left[j] <= right[k])
		{
			arr[i] = left[j];
			++j;
		}
		else
		{
			arr[i] = right[k];
			++k;
		}
		++i;
	}
	while(j < leftNrOf)
	{
		arr[i] = left[j];
		++j;
		++i;
	}
	while(k < rightNrOf)
	{
		arr[i] = right[k];
		++k;
		++i;
	}
} 

template<typename T>
void mergeSortRecursive(T arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex) // 
	{
		int midIndex = (startIndex + endIndex) / 2;
		mergeSortRecursive(arr, startIndex, midIndex); // choosing left side
		mergeSortRecursive(arr, midIndex + 1, endIndex); //choosing right side
		merge(arr, startIndex, midIndex, endIndex); //merge the two arrays in correct order
	}
}



template<typename T>
void mergeSort(T arr[], int nrOf)
{
	mergeSortRecursive(arr, 0, nrOf - 1);
}
