#ifndef QUICKSORT_H
#define QUICKSORT_H
template <typename T>
int partition(std::vector<std::tuple<T,T,int>> &arr, int startIndex, int endIndex)
{
	int pivot = std::get<2>(arr[startIndex]);
	int i = startIndex;
	for (int j = startIndex + 1; j <= endIndex; j++)
	{
		if (std::get<2>(arr[j]) < pivot)
		{
			std::swap(arr[j], arr[++i]);
		}
	}
	std::swap(arr[startIndex], arr[i]);
	return i;
}


template <typename T>
void quickSort(std::vector<std::tuple<T,T,int>> &arr, int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int pivotIndex = partition(arr, startIndex, endIndex);
		quickSort(arr, startIndex, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, endIndex);
	}

}

template <typename T>
void quickSort(std::vector<std::tuple<T,T,int>> &arr, int nrOf)
{
	quickSort(arr, 0, nrOf - 1);
}
#endif