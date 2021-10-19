#include <iostream>
#include <string>
#include "RedBlackTree.h"

using namespace std;

void test2()
{
	RedBlackTree <int,int> obj;
	int i = 0;
	obj.insert(12,++i);
	obj.insert(11,++i);
	obj.insert(10,++i);
	obj.insert(25,++i);
	obj.insert(1,++i);
	obj.insert(0,++i);
	obj.remove(0);
	obj.remove(10);
	obj.insert(7, ++i);
	obj.insert(8, ++i);
	obj.insert(0, ++i);
	obj.remove(7);
	obj.print();
	obj.remove(1);
	// obj.print();
	obj.remove(12);
	obj.print();
	cout << endl;
	system("pause");
	vector<int> values = obj.values();
	for (int i = 0; i < values.size(); i++)
		cout << values[i] << ",";
	cout << endl;
	cout << obj.size() << endl;
	cout << obj.search(7) << endl;
	vector<int> keys = obj.keys();
	for (int i = 0; i < keys.size(); i++)
		cout << keys[i] << ",";
	cout << endl;
	obj.insert(7,7);
	cout << obj.search(7) << endl;
	system("pause");
	////obj.insert(8,8);
	////obj.insert(9,9);
	////obj.insert(10,10);
	////obj.insert(11,11);
	RedBlackTree <int,int>obj2(obj);
	//obj.insert(12, 12);
	//obj.Print();
	//cout << endl << endl;
	//obj2.Print();
	//cout << endl << "After Deletion" << endl;
	////obj.Delete(40);
	////obj.Print();
	////RedBlackTree<int, int> obj3;
	//obj.insert(1, 1);
	obj2 = obj;
	obj2.print();
	RedBlackTree<int, char> rb1;
	if (rb1.insert(6, 'f')) cout << "inserted 42" << endl;
	rb1.insert(10, 'j');
	rb1.insert(2, 'b');
	//RedBlackTree<int, char> rb2(rb1);

	if (rb1.remove(2)) cout << "removed 2" << endl;
	if (rb1.search(6)) cout << "found 6" << endl;

	vector<char> v1 = rb1.search(8, 21); //should contain j
	vector<char> v2 = rb1.values(); //should contain {f, j}
	vector<int> v3 = rb1.keys(); //should contain {6, 10}

	cout << "size = " << rb1.size() << endl; //should be 2
	NodeT<int, char>* pRoot = rb1.getRoot(); //BAD design - for our testing only
	system("pause");
}

void simpleTest()
{
	// Int Tree Tests	
	RedBlackTree<int, char> rb1;
	if (rb1.insert(6, 'f')) cout << "inserted 42" << endl;
	rb1.insert(10, 'j');
	rb1.insert(2, 'b');
	RedBlackTree<int, char> rb2(rb1);
 
	if (rb1.remove(2)) cout << "removed 2" << endl;
	if (rb1.search(6)) cout << "found 6" << endl;
 
	vector<char> v1 = rb1.search(8, 21); //should contain j
	vector<char> v2 = rb1.values(); //should contain {f, j}
	vector<int> v3 = rb1.keys(); //should contain {6, 10}
 
	cout << "size = " << rb1.size() << endl; //should be 2
	NodeT<int, char>* pRoot = rb1.getRoot(); //BAD design - for our testing only
}

int main() 
{
	simpleTest();
	test2();
}

