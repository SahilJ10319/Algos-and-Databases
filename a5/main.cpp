#include <iostream>
#include <vector>
#include "Heap.h"
using namespace std;

void simpleTest();
void SmallestM1();
void MergeTest();

void MergeTest()
{
	cout << "Tesing Merge Function: " << endl;
	Heap<int> hp1(3);
	Heap<int> hp2(3);
	hp1.insert(3);
	hp1.insert(2);
	hp1.insert(1);
	//hp1.insert(11);

	hp2.insert(6);
	hp2.insert(4);
	hp2.insert(5);

	Heap<int> hp3 = hp1.merge(hp2);
	cout << "\n\n";
}

void SmallestM1()
{
	cout << "Testing Smalllest M: " << endl;
	cout << "Test #1: \n";
	vector<float> v1 = { 10.7, 5.5, 2.4, 2.5, 6.5, 4.9, 3.3, 9.3 ,1.2 };
	vector<float> ret = smallestm<float>(v1, 9);
	for (unsigned int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;

	cout << "Test #2: \n";
	vector<int> v2 = { 10,5,2,8,6,4,3,9,1 };
	vector<int> ret2 = smallestm<int>(v2, 9);
	for (unsigned int i = 0; i < ret2.size(); i++)
	{
		cout << ret2[i] << " ";
	}
	cout << endl;
	cout << "\n\n";
}

void simpleTest()
{   
	cout << "Provided Simple Test: " << endl;
	// Int Heap Tests
	Heap<int> pq1(4);

	pq1.insert(3);
	pq1.insert(1);
	pq1.insert(42);

	cout << "pq1 root = " << pq1.peek() << endl; //42
	int urgent = pq1.remove();
	cout << "pq1 root = " << pq1.peek() << endl; //3
	cout << "pq1 size = " << pq1.size() << endl; //2

	Heap<int> pq2(pq1);
	pq2.insert(13);
	Heap<int> pq3 = pq1.merge(pq2); // should contain duplicates
	cout << "pq3 size = " << pq3.size() << endl; //5
	cout << "pq3 root = " << pq3.peek() << endl; //13
	cout << "\n\n";
}

int main()
{
	simpleTest();
	SmallestM1();
	MergeTest();
}

