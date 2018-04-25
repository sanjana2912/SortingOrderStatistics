// Siddharth Agarwal 
// github.com/siddhx
// main.cpp : entry point for the console application.
// references https://www.geeksforgeeks.org/heap-sort/
// Heap Sort implementation
//
#include <stdio.h>
#include "heapSort.h"
#include <iostream>
using namespace std;

int main()
{
	quickSort S;
	// use input from a file or a random number generator.
	float arr[] = { 12, 11.55, 13, 5.6, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	S.heapSort(arr, n);

	cout << "Sorted array is \n";
	S.printArray(arr, n);
}