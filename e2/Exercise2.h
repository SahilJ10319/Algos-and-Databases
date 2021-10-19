#pragma once

int remove(int *arr, int &size, int value) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            for (int k = i; k < size - 1; k++) {
                int copy = arr[k];
                arr[k] = arr[k + 1];
                arr [k + 1] = copy;
            }
            counter++;
            size--;
            i--;
        }
    }
    return counter;
}
