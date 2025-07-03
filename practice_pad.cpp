
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PP_BubbleSort(vector<int>& arr, int n)
{
	bool swapped = false;

	for (int i = 0; i < n - 1; ++i)
	{
		swapped = false;
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
		{
			break;
		}
	}
}

int PP_Partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; ++j)
	{
		if (arr[j] <= pivot)
		{
			++i;
			swap(arr[i], arr[j]);
		}
	}
	
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void PP_QuickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = PP_Partition(arr, low, high);

		PP_QuickSort(arr, low, pi - 1);
		PP_QuickSort(arr, pi + 1, high);
	}
}

void PP_Merge(vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<int> leftArr(n1), rightArr(n2);

	for (int i = 0; i < n1; ++i)
	{
		leftArr[i] = arr[left + 1];
	}

	for (int i = 0; i < n2; ++i)
	{
		rightArr[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i++];
		}
		else
		{
			arr[k] = rightArr[j++];
		}
		++k;
	}

	while (i < n1)
	{
		arr[k++] = leftArr[i++];
	}

	while (j < n2)
	{
		arr[k++] = rightArr[j++];
	}
}

void PP_MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		PP_MergeSort(arr, left, mid);
		PP_MergeSort(arr, mid + 1, right);
		PP_Merge(arr, left, mid, right);
	}
}
