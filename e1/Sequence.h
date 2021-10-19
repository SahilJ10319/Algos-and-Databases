#pragma once
class Sequence 
{
public:
    // Default Constructor
    Sequence();

    //Destructor
    ~Sequence();

    void insert(double n);

    void clear();

    int size() const;

    double stdDeviation() const;

};
