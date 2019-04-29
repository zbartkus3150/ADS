#include "MergeSort.h"

void main() {
	int arr[] = { -1, 2, 5, 0, 4, 3, 2, 1 };
	PrintM(arr, 8);
	//int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, 7);
	//PrintM(arr, 8);
}