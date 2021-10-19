#pragma once
#include <vector>
// For the implementation of Shell Sort and instances of other functions
// GeeksforGeeks was used
// Stack Overflow was used
// Math overflow was used
// For Merge Sort and Quicksort, C++ textbook was used

using std::vector;

template <class T>
int insertionsort(T arr[], int n)
{
	int comparisons = 0;

    for (int i = 1; i < n; i++)
    {
        T key = arr[i];
        int position = i - 1;

        // Move arr elements up if greater than key
        while (position >= 0 && arr[position] > key)
        {
            comparisons++;
            arr[position + 1] = arr[position];
            position--;
        }
        arr[position + 1] = key;
    }
	return comparisons;
}

//===============================================================

// Helper Function to Swap
template <class T>
void swap(T* first, T* second)
{
    T temp = *first;
    *first = *second;
    *second = temp;
}

// Helper function to Partition for Quidksort
template <class T>
int partition(T *arr, int start, int end, int &comparisons)
{
    T x = arr[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) 
    {
        comparisons++;
        if (arr[j] <= x) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}

template <class T>
int quicksort(T arr[], int n)
{
    int comparisons = 0;
    int start = 0;
    int end = n - 1;
    int *stack = new int[end - start + 1];

    // initialize top of stack 
    int top = -1;

    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0) 
    {
        // Pop both Start and End
        end = stack[top--];
        start = stack[top--];

        // Set pivot in correct place
        int p = partition(arr, start, end, comparisons);

        // For the two if statements, if elements exists on left and/or right
        // side of pivot, push to stack
        if (p - 1 > start) 
        {
            stack[++top] = start;
            stack[++top] = p - 1;
        }

        if (p + 1 < end) 
        {
            stack[++top] = p + 1;
            stack[++top] = end;
        }
    }
    return comparisons;
}

//===============================================================

//Merge Sort's Merge Function
// Used Professor Edgar's implementation
// l = low
// m = mid
// h = high
template <class T>
void merge(T arr[], int l, int m, int h, int& comparisons)
{
	int start1 = l;
	int end1 = m;
	int start2 = m + 1;
	int end2 = h;
	int i1 = start1;
	int i2 = start2;

	vector<T>temp;

	while (i1 <= end1 && i2 <= end2)
	{
		if (arr[i1] < arr[i2])
		{
			temp.push_back(arr[i1]);
			i1++;
		}
		else
		{
			temp.push_back(arr[i2]);
			i2++;
		}
	}

	while (i1 <= end1)
	{
		temp.push_back(arr[i1]);
		i1++;
	}
	while (i2 <= end2)
	{
		temp.push_back(arr[i2]);
		i2++;
	}

	for (unsigned int itemp = 0; itemp < temp.size(); itemp++)
	{
		arr[itemp + l] = temp[itemp];
		comparisons++;
	}
}

//Minimum calculator
int min(int x, int y)
{
	int ret;
	if (x < y)
	{
		ret = x;
	}
	else
	{
		ret = y;
	}
	return ret;
}

//Helper function which makes divides the array and calls merge to combine the subarrays 
template <class T>
void MShelper(T arr[], int size, int& comparisons)
{
	for (int curr = 1; curr <= size; curr = 2 * curr)
	{
		for (int l = 0; l < size; l += 2 * curr)
		{
			int m = min(l + curr - 1, size);
			int h = min(l + 2 * curr - 1, size);
			merge(arr, l, m, h, comparisons);
		}
	}
}

//Merge sort 
template <class T>
int mergesort(T arr[], int size)
{
	int comparisons = 0;
	MShelper(arr,size - 1, comparisons);
	return comparisons;
}

//===============================================================
template <class T>
int shellsort(T arr[], int n)
{
	int comparisons = 0;

    // Start with a big gap, then reduce the gap 
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size. 
        for (int i = gap; i < n; i++)
        {
            // add a[i] to the elements that have been gap sorted 
            T temp = arr[i];

            // shift elements
            comparisons++;
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // put in correct order
            arr[j] = temp;
        }
    }
    return comparisons;
}

