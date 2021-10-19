#include<iostream>
#include"cmpt225sort.h"
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

void Test1();
void Test2();
void Test3();
void Test4();

void Test1()
{
	cout << "\tTesting Insertion sort:\n";
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	int ret = insertionsort<int>(arr, 20);
	cout << "Array after sorting = ";
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Number of barometer operations = " << ret<<endl;
}

void Test2()
{
	cout << "\n\tTesting Quicksort:\n";
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };//best case is choosing a pivot that divides the array evenly 
	int ret = quicksort<int>(arr, 20);
	cout << "Array after sorting = ";
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Number of barometer operations = " << ret << endl;
}

void Test3()
{
	cout << "\n\tTesting Mergesort:\n";
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	int ret = mergesort<int>(arr, 20);
	cout << "Array after sorting = ";
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Number of barometer operations = " << ret << endl;

}

void Test4()
{
	cout << "\n\tTesting Shellsort:\n";
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int ret = shellsort<int>(arr, 20);
	cout << "Array after sorting = ";
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Number of barometer operations = " << ret << endl;

	//20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
}

// PARAM: infile = name of the file to be opened
//        n = the size of the result array
// PRE: the file contains values separated by white space
// POST: returns an array containing the contents of infile
template <class T>
T* readFile(string infile, int& n)
{
	T* result;
	T next;
	n = 0;

	ifstream ist(infile.c_str()); // open file
	// Check if file opened correctly
	if (ist.fail()) {
		throw runtime_error(infile + " not found");
	}

	// Find file size
	while (ist >> next) {
		n++;
	}

	// Read file into array
	ist.close();
	ist.open(infile.c_str());
	result = new T[n];
	for (int i = 0; i < n; ++i) {
		ist >> result[i];
	}

	ist.close();
	return result;
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	cout << "\nProvided test:\n";
	int n = 0;
	int* arr1 = readFile<int>("a3test1.txt", n);
	cout << "insertion sort comparisons = " << insertionsort<int>(arr1, n) << endl;
	float* arr2 = readFile<float>("a3test2.txt", n);
	cout << "quicksort comparisons = " << quicksort<float>(arr2, n) << endl;
	string* arr3 = readFile<string>("a3test3.txt", n);
	cout << "mergesort comparisons = " << mergesort<string>(arr3, n) << endl;
	cout << "shell sort comparisons = " << shellsort<string>(arr3, n) << endl;
	return 0;
}


//===============================================================
//Merge Sort's Merge Function-checked
/* template <class T>
void merge(T arr[], int low, int mid, int high, int& baro)
{
	int start1 = low;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = high;
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
		arr[itemp + low] = temp[itemp];
		baro++;
	}


}

template <class T>
int min(int x, int y)
{
  int ret;
  if(x<y)
  {
    ret = x;
  }
  else
  {
    ret = y;
  }
  return ret;
}

//
template <class T>
void MShelper(T arr[], int size, int& baro)
{
	for(int curr = 1;curr<= size;curr = 2*curr)
  {
    for(int low = 0; low<size;low += 2*curr)
    {
      int mid = min(low+curr-1,size);
      int high = min(low+2*curr-1,size);
      merge(arr,low,mid,high,baro);
    }
  }
}


//Merge sort 
template <class T>
int mergesort(T arr[], int size)
{
	int baro = 0;
	MShelper(arr,size-1, baro);

	return baro;
} */