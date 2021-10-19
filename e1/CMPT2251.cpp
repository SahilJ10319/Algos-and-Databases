#include <iostream>
#include <iomanip>
#include "Sequence.h"

using namespace std;

void exercise1()
{
    Sequence sq;
    sq.insert(2.1);
    cout << "size = " << sq.size() << endl; // outputs 0
    cout << "standard deviation = " << sq.stdDeviation() << endl; // outputs 0
    sq.clear();
}

int main() {
    exercise1();
}