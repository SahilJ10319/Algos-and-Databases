#include "LinkedList.h"

// To be completed for exercise 4
// Recursive helper method for remove(int)
// ONLY CHANGE BODY OF THIS METHOD
void LinkedList::remove(Node* nd, int val)
{
    if (nd == nullptr)
    {
        return;
    }
    if (nd->next == nullptr && nd->data != val)
    {
        return;
    }
    Node* current = nd->next;
    Node* past = nd;

    if(past->data == val && past == head)
    {
        head = head->next;
        delete past;
        return remove(current, val);
    }
    else if (current->data == val)
    {
        past->next = current->next;
        delete current;
        return remove(past, val);
    }
    else
    {
        return remove(current, val);
    }  
}

// Constructors and destructor
// Creates an empty list
LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	deleteList();
}
// Copy constructor and overloaded assignment operator not implemented

// Mutators------------------
// PARAM: val = value to be inserted
// POST: inserts val at the front of the list
void LinkedList::insert(int val)
{
	Node* newNode = new Node(val, head);
	head = newNode;
}

// PARAM: val = value to be removed from list
// POST: removes all incidences of val from list,
// Calls remove(Node*, int)
void LinkedList::remove(int val)
{
	remove(head, val);
}

// Helper method for destructor
// (and un-implemented overloaded assignment operator)
void LinkedList::deleteList()
{
	Node* temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// Accessors
bool LinkedList::check(const vector<int> & v)
{
	Node* p = head;
	for (int x : v) {
		if (p == nullptr || p->data != x) {
			return false;
		}
		p = p->next;
	}
	return (p == nullptr); // p != nullptr list contains unchecked values
}