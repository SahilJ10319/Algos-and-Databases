#pragma once 
#include <iostream>
#include <cmath>
#include <new>
#include <algorithm>

class Sequence 
{
private:
    int capacity;
    int sz;
    double* arr;

public:
    Sequence();

    Sequence(const Sequence & seq);

    ~Sequence();

    Sequence & operator=(const Sequence & seq);

    void insert(double value);

    void insert(double arr1[], int arrSize);

    int find(double value) const;

    int size() const;

    double sum() const;

    double mean() const;

    double median() const;

    double stddev() const;

    Sequence & concatenate(const Sequence & seq) const;

    // void print() const;

};