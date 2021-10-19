#include "Deque.h"

using namespace std;

int main()
{
       Deque<int> dq1;
       cout << dq1.empty() << " - 1" << endl;
       dq1.insertFront(42);
       dq1.insertBack(216);
       cout << dq1.peekFront() << " - 42" << endl;
       cout << dq1.peekBack() << " - 216" << endl;
       cout << dq1.size() << " - 2" << endl;

       Deque<int> dq2(dq1);
       Deque<int> dq3;
       dq3 = dq1;

       cout << dq1.removeFront() << " - 42" << endl;
       cout << dq1.removeBack() << " - 216" << endl;

       cout << dq2.peekFront() << " - 42" << endl;
       cout << dq2.peekBack() << " - 216" << endl;
       cout << dq3.peekFront() << " - 42" << endl;
       cout << dq3.peekBack() << " - 216" << endl;
       return 0;
}