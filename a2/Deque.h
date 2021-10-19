#pragma once
#include <iostream>
#include <new>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <cstddef>

// Node Class
template <class T>
class Node
{
public:
    T data;
    Node *next, *previous;
// Constructor
    Node(T value)
    : data(value), next(nullptr), previous(nullptr)
    {   }
};

// Deque Class
template <class T>
class Deque
{
private:
    Node<T>* front;
    Node<T>* back;
    int sz;
public:
    Deque();
    Deque(const Deque & Deq);
    ~Deque();
    Deque & operator=(const Deque & Deq);
    void insertFront(T value);
    void insertBack(T value);
    T removeFront();
    T removeBack();
    T peekFront() const;
    T peekBack() const;
    bool empty() const;
    int size() const;
};

template <class T>
// Default Constructor
Deque<T>::Deque()
: front(nullptr), back(nullptr), sz(0)
{   }

template <class T>
// Copy Constructor
Deque<T>::Deque(const Deque & Deq)
{
    front = nullptr;
    back = nullptr;
    Node<T>* temp = Deq.front;
    while(temp != nullptr)
    {
        insertBack(temp->data);
        temp = temp->next;
    }
    sz = Deq.sz;
}

template <class T>
// Destructor
Deque<T>::~Deque()
{
    while(front != nullptr)
    {
        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }
    front = nullptr;
    back = nullptr;
}

template <class T>
// Operator = Method
// Deletes a Linked List associated with the calling object and copy data from 
// List passed to calling object
// E.G. (Deq3 = Deq 2)
Deque<T> & Deque<T>::operator=(const Deque & Deq)
{
    if(this != &Deq)
    {
        while(front != nullptr)
        {
            Node<T>* copy = front;
            front = front->next;
            delete copy;
        }
        front = nullptr;
        back = nullptr;

        Node<T>* temp = Deq.front;
        while(temp != nullptr)
        {
            insertBack(temp->data);
            temp = temp->next;
        }
        sz = Deq.sz;
    }
    return *this;
}

template <class T>
// Insert Front
// 
void Deque<T>::insertFront(T value)
{
    if(front == nullptr)
    {
        Node<T>* node = new Node<T>(value);
        front = node;
        back = node;
    }
    else
    {
        Node<T>* node = new Node<T>(value);
        node->next = front;
        node->previous = nullptr;
        front->previous = node;
        front = node;
    }
    sz++;
}

template <class T>
// Insert Back
void Deque<T>::insertBack(T value)
{
    if(back == nullptr)
    {
        Node<T>* node = new Node<T>(value);
        front = node;
        back = node;
    }
    else
    {
        Node<T>* node = new Node<T>(value);
        node->next = nullptr;
        back->next = node;
        node->previous = back;
        back = node;
    }
    sz++;
}

template <class T>
// Remove Front
T Deque<T>::removeFront()
{
    if(empty())
    {
        throw std::runtime_error("List is Empty");
    }
    Node<T>* temp = this->front;
    this->front = this->front->next;
    T value = temp->data;
    delete temp;
    sz--;
    return value;
}

template <class T>
// Remove Back
T Deque<T>::removeBack()
{
    if(empty())
    {
        throw std::runtime_error("List is Empty");
    }
    Node<T>* temp = this->back;    
    T value = temp->data;
    this->back = this->back->previous;     
    this->back->next = nullptr;
    sz--;
    return value;
}

template <class T>
// Peek Front
T Deque<T>::peekFront() const
{
    if (empty())
    {
        throw std::runtime_error("List is Empty");
    }
    return front->data;
}

template <class T>
// Peek Back
T Deque<T>::peekBack() const
{
    if (empty())
    {
        throw std::runtime_error("List is Empty");
    }
    return back->data;
}

template <class T>
// Empty Check Method
bool Deque<T>::empty() const
{
    return sz==0;
}

template <class T>
// Size Method
int Deque<T>::size() const
{
    return sz;
}



