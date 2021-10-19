#include "Sequence.h"

// Default Constructor
// Create an array of capacity 2 and size 0
Sequence::Sequence()
: capacity(2), sz(0), arr(new double[capacity])
{   }

// Copy Constructor
// Copies content of Array Passed Through
Sequence::Sequence(const Sequence & seq)
: capacity(seq.capacity), sz(seq.sz), arr(new double[capacity])
{
    for(int i = 0; i < sz; ++i) 
    {
        arr[i] = seq.arr[i];
    }
}

// Destructor
// Deallocates Memory
Sequence::~Sequence()
{
    delete[] arr;
    arr = nullptr;
}

// Overloaded Assignment Operator
Sequence & Sequence::operator=(const Sequence & seq)
{
    if(this != &seq)
    {
        delete[] arr;
        sz = seq.sz;
        capacity = seq.capacity;
        arr = new double[capacity];
        for (int i = 0; i < sz; ++i) 
        {
            arr[i] = seq.arr[i];
        }
    }
    return *this;
}

// Insert Method
// Insert an element to the Array
void Sequence::insert(double value)
{
    if (sz >= capacity) 
    {
        capacity *= 2;
        double* tempArr = new double[capacity];

        for (int i = 0; i < sz; ++i) 
        {
            tempArr[i] = arr[i];
        }
        delete[] arr;
        arr = tempArr;
    }
    else 
    {
        arr[sz] = value;
        sz++;
    }
}

// Insert Method
// Inserts the values stored in its (first) double array parameter 
// at the end of the calling object's array
void Sequence::insert(double arr1[], int arrSize)
{
    if((sz + arrSize) >= capacity)
    {
        int index = 0;
        capacity = sz + arrSize;
        double* oldArr = arr;
        double* tempArr = new double[capacity];

        for(int i = 0; i < sz; i++)
        {
            tempArr[i] = oldArr[i];
        }
        for(int j = sz; j < capacity; j++)
        {
            tempArr[j] = arr1[index];
            index++;
        }
        arr = tempArr;
        delete[] oldArr;
        sz = capacity;
    }
    else 
    {
        for(int i = sz; i < sz + arrSize; i++)
        {
            arr[i] = arr1[i];
        }
        sz = (sz + arrSize);
    }
} 

// Find Method
// Returns an integer equal to the number of sequence elements 
// whose value is equal to its double parameter
int Sequence::find(double value) const
{
    int counter = 0;
    for(int i = 0; i < sz; i++) 
    {
        if (arr[i] == value) {
            counter++;
        }
    }
    return counter;
}

// Size Method
// Returns Size of The Array in the Calling Object
int Sequence::size() const
{
    return sz;
}

// Sum Method
// Sums the values of the underlying array
double Sequence::sum() const
{
    double sum = 0.0;
    for (int i = 0; i < sz; ++i) 
    {
        sum = sum + arr[i];
    }
    return sum;
}

// Calculate Mean Method
// Averages values in calling object
double Sequence::mean() const
{
    double Sum = this->sum();
    double average = (Sum / sz);
    return average;
}

// Calculate Median Method
// Finds Median of the Calling Object
double Sequence::median() const
{
    std::sort(arr, arr + sz);
    double median = 0.0;
// If even, average two middle indexs
    if(sz % 2 == 0) 
    {
        median = (arr[(sz - 1) / 2] + arr[sz / 2]) / 2.0;
    }
    // If odd, find middle index
    else 
    {
        median = arr[sz/2];
    }
    return median;
}

// Calculate Standard Deviation Method
// Finds Standard Deviation of objects in Calling Object
double Sequence::stddev() const
{
    double sd;
    double sum = 0.0;
    double mean = this->mean();
    for(int i = 0; i < sz; ++i)
    {
        sum += (sqrt(arr[i] - mean));
    }
    sd = sqrt(sum / (sz - 1));
    return sd;
}

// Concatenate Method
// Links constant Sequence reference parameter and calling object array
Sequence & Sequence::concatenate(const Sequence & seq) const
{
    Sequence *Sq = new Sequence;
    Sq->insert(arr, sz);
    Sq->insert(seq.arr, seq.sz);
    return *Sq;
} 

/* void Sequence::print() const
{
    for(int i = 0; i < sz; i++)
    {
        std::cout << arr[i] << std::endl;
    }
} */

