#include <iostream>

using namespace std;

int remove(int *arr, int &size, int value) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            for (int k = i; k < size - 1; k++) {
                int t = arr[k];
                arr[k] = arr[k + 1];
                arr [k + 1] = t;
            }
            counter++;
            size--;
            i--;
        }
    }
    return counter;
}

int main() {
    int arr[] = {1, 2, 3, 6, 6, 4, 5, 6, 6, 6, 6};
    int size = 11;
    cout << remove(arr,size,6) << endl;
    cout << size;
    return 0;
}