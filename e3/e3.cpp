#include <iostream>
#include <string>

using namespace std;

bool bar(string s, int i, int j)
{
    if (i >= j) {
        return true;
    }
    else if (s[i] != s[j]) {
        return false;
    }
    else {
        return bar(s, i + 1, j - 1);
    }
}

bool foo(string s) {
    return bar(s, 0, s.size() - 1);
}
 
int main() {
    cout << foo("defense") << endl;
}