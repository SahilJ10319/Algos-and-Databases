#pragma once
#include <iostream>
#include<stdexcept>
#include<cstddef>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

// Used GeeksforGeeks

template <class T>
vector<T> smallestm(vector<T>& v1, int m);


template <class T>
class Heap
{
private:
	int currSize;
	int maxSize;
	T* arr;
	void bubbleUp(int index);
	void bubbleDown(int index);

public:
	Heap(int size);
	Heap(const Heap& hp);
	~Heap();
	Heap& operator=(const Heap& hp);
	void insert(T value);
	T remove();
	T peek()const;
	Heap& merge(const Heap& hp);
	int size()const;

};


//Part 2

template <class T>
vector<T> smallestm(vector<T>& v1, int m)
{
	//Create a vector and temp for result and management	
	vector<T> ret;
	vector<T> temp;
	Heap<T> hp(v1.size());
	
	for (unsigned int i = 0; i < v1.size(); i++)
	{
		hp.insert(v1[i]);
	}
	//If true, return the passed vector
	if (m >= int(v1.size()))
	{
		for (unsigned int i = 0; i < v1.size(); i++)
		{
			temp.push_back(hp.remove());
		}
		//Change order from ascending to descending
		for (unsigned int j = 0; j < temp.size(); j++)
		{
			ret.push_back(temp[temp.size()-(j+1)]);
		}
	}
	else
	{
		while (hp.size() != m)
		{
			hp.remove();
		}
		while (hp.size() != 0)
		{	
			temp.push_back(hp.remove());
		}
		for (int i = 0; i < temp.size(); i++)
		{
			ret.push_back(temp[temp.size() - (i + 1)]);
		}
	}
	return ret;
}


//Part 1

//Default Constructor
template <class T>
Heap<T>::Heap(int size)
{
		arr = new T[size];
		maxSize = size;
		currSize = 0;
}


//Copy Constructor
template <class T>
Heap<T>::Heap(const Heap& hp)
{
	currSize = hp.currSize;
	maxSize = hp.maxSize;
	arr = new T[maxSize];
	for (int i = 0; i < currSize; i++)
	{
		arr[i] = hp.arr[i];
	}
}


//Destructor
template<class T>
Heap<T>::~Heap()
{
	delete[] arr;
	arr = nullptr;

}



//Overloaded Assignment Operator
template <class T>
Heap<T>& Heap<T>::operator=(const Heap<T>& hp)
{
	if (&hp != this)
	{
		delete arr;
		arr = new T[hp.maxSize];
		currSize = hp.currSize;
		maxSize = hp.maxSize;
		for (int i = 0; i < currSize; i++)
		{
			arr[i] = hp.arr[i];
		}
	}
	return *this;
}


//Insert 
template <class T>
void Heap<T>::insert(T value)
{
	if (currSize >= maxSize)
	{
		throw std::runtime_error("array is full");
	}
	arr[currSize] = value;
	currSize++;
	bubbleUp(currSize - 1);
}


//Remove
template <class T>
T Heap<T>::remove()
{
	if (currSize == 0)
	{
		throw std::runtime_error("array is empty");
	}
	T value = arr[0];
	arr[0] = arr[currSize - 1];
	currSize--;
	bubbleDown(0);
	
	return value;
}


//Peek
template <class T>
T Heap<T>::peek()const
{
	if (currSize == 0)
	{
		throw std::runtime_error("array is empty");
	}

	return arr[0];
}


//Merge
template <class T>
Heap<T>& Heap<T>::merge(const Heap<T>& hp2)
{
	Heap<T>* hp3 = new Heap<T>(currSize + hp2.currSize);
    
	for (int i = 0; i < currSize; i++)
	{
		hp3->insert(arr[i]);
	}

	for (int j = 0; j < hp2.currSize; j++)
	{
		hp3->insert(hp2.arr[j]);
	}
	//For Testing
	/*cout << "Merge Test" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << hp3->arr[i] << " ";
	}
	cout << "\n\n";*/
	return *hp3;
}


//Size
template <class T>
int Heap<T>::size()const
{
	return currSize;
}


//Helper to fix heap properties after insertion
template <class T>
void Heap<T>::bubbleUp(int index)
{
	int parent = (index - 1) / 2;
	if (index > 0 && arr[index] > arr[parent])
	{
		T temp = arr[index];
		arr[index] = arr[parent];
		arr[parent] = temp;
		bubbleUp(parent);
	}	
}


//Helper to fix heap properties after removal
template <class T>
void Heap<T>::bubbleDown(int index)
{
	int child_1 = 2 * (index)+1;
	int child_2 = 2 * (index)+2;
	
	if (child_1 < currSize)
	{
		if (child_2 < currSize)
		{
			if (arr[child_1] > arr[index] && arr[child_1] > arr[child_2])
			{
				T temp = arr[child_1];
				arr[child_1] = arr[index];
				arr[index] = temp;
				bubbleDown(child_1);
			}
			else if(arr[child_2]> arr[index])
			{
				T temp = arr[child_2];
				arr[child_2] = arr[index];
				arr[index] = temp;
				bubbleDown(child_2);
			}
		}
		else
		{
			if (arr[child_1] > arr[index])
			{
				T temp = arr[child_1];
				arr[child_1] = arr[index];
				arr[index] = temp;
				bubbleDown(child_1);
			}
		}
	}
	
}