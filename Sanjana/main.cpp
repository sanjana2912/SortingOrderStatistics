#include "RandomizedQuickSort.h"
#include "FirstQuickSort.h"
#include "MedianofthreeQuickSort.h"
#include <iostream>

using namespace std;

void quickSort_first(int arr[], int low, int high)
{
    if (low < high) {

         int pi = FirstQuickSort::partition1(arr, low, high);
         quickSort_first(arr, low, pi - 1);
         quickSort_first(arr, pi + 1, high);
    }
}
void quickSort_random(int arr[], int low, int high)
{
    if (low < high) {

        //pi is partitioning index, arr[p] is now at right place
        int pi = RandomizedQuickSort::partition_r(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort_random(arr, low, pi - 1);
        quickSort_random(arr, pi + 1, high);
    }
}

void quickSort_median(int arr[], int low, int high)
{
    if (low < high) {

        int pi = MedianofthreeQuickSort::partition_median(arr, low, high);
        quickSort_median(arr, low, pi - 1);
        quickSort_median(arr, pi + 1, high);
    }
}

/* Function to print an array */
void print_Array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
  //input file generator code
    int arr[] = { 56, 67, 18, 9, 11, 45 };
    int n = sizeof(arr) / sizeof(arr[0]);
//    quickSort_random(arr,0,n-1);
//    quickSort_median(arr, 0, n - 1);
    quickSort_first(arr,0,n-1);
    //display the output in form of an array
    printf("Sorted array: \n");
    print_Array(arr, n);
    return 0;
}