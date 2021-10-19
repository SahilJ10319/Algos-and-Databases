#pragma once
#include <math.h>

bool isMinHeap(int arr[], int size) {
	long int currNode = 0; // start from the root
	int firstChildIndex = 0;
	int secondChildIndex = 0;
	double level = floor(log2(size));
	double stopLoop = pow(2.0, level);
	while (currNode != stopLoop-1) {
		firstChildIndex = (2*currNode)+1;

		secondChildIndex = (2*currNode)+2;

		if (firstChildIndex > size-1) {
			break;
		}
		else if (secondChildIndex > size-1) {
			if (arr[firstChildIndex] < arr[currNode])
			{
				return false;
			}
			break;
		}
		else {
			if (arr[firstChildIndex] < arr[currNode] || arr[secondChildIndex] < arr[currNode])
			{
				return false;
			}
		}
		currNode++;
	}
	return true;
} 