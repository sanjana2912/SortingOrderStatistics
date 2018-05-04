#include <iostream>
#include "optimizedquicksort.h"

using namespace std;

// Number of elements to be sorted
#define N 1000000

// perform insertion sort on arr[]
void insertionSort(int arr[], int low, int n)
{
    // Start from second element (element at index 0 
    // is already sorted)
    for (int i = low + 1; i <= n; i++) 
    {
        int value = arr[i];
        int j = i;
        
        // Find the index j within the sorted subset arr[0..i-1]
        // where element arr[i] belongs
        while (j > low && arr[j - 1] > value) 
        {
            arr[j] = arr[j - 1];
            j--;
        }
        // Note that subarray arr[j..i-1] is shifted to
        // the right by one position i.e. arr[j+1..i]
        
        arr[j] = value;
    }
}
 
int Partition (int a[], int low, int high)
{
    // Pick rightmost element as pivot from the array
    int pivot = a[high];

    // elements less than pivot will be pushed to the left of pIndex
    // elements more than pivot will be pushed to the right of pIndex
    // equal elements can go either way
    int pIndex = low;    
    
    // each time we finds an element less than or equal to pivot, pIndex
    // is incremented and that element would be placed before the pivot. 
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    // swap pIndex with Pivot
    swap (a[pIndex], a[high]);
    
    // return pIndex (index of pivot element)
    return pIndex;
}

void QuickSort(int a[], int low, int high)
{
    // base condition
    if(low >= high)
        return;

    // rearrange the elements across pivot
    int pivot = Partition(a, low, high);

    // recurse on sub-array containing elements that are less than pivot
    QuickSort(a, low, pivot - 1);

    // recurse on sub-array containing elements that are more than pivot
    QuickSort(a, pivot + 1, high);
}

void optimizedQuickSort::calcOptimizedQuickSort(int arr[], int low, int high, int NUM)
{
    while (low < high) 
    {
        // do insertion sort if 10 or smaller
        if(high - low < NUM)
        {
            insertionSort(arr, low, high);
            break;
        }
        else 
        {
            int pivot = Partition(arr, low, high);
            
            // tail call optimizations - recurse on smaller sub-array
            if (pivot - low < high - pivot) {
                optimizedQuickSort::calcOptimizedQuickSort(arr, low, pivot-1, NUM);
                low = pivot + 1;
            } else {
                optimizedQuickSort::calcOptimizedQuickSort(arr, pivot+1, high, NUM);
                high = pivot - 1;
            }
        }
    }    
}