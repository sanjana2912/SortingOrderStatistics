//
// Created by Sanjana on 21-04-2018.
//

#include "RandomizedQuickSort.h"
#include <iostream>
using namespace std;



// A utility function to swap two elements
void RandomizedQuickSort::swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int RandomizedQuickSort::partition_r(int *arr, int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap A[random] with A[high]
    swap(&arr[random], &arr[high]);

    return RandomizedQuickSort::partition(arr, low, high);

}

int RandomizedQuickSort::partition(int *arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {

            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
