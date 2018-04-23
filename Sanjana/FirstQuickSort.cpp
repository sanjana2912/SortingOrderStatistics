//
// Created by Sanjana on 21-04-2018.
//
#include "FirstQuickSort.h"
//
// Created by Sanjana on 20-04-2018.
//

using namespace std;
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/* This function takes last element as pivot, places
  the pivot element at its correct position in sorted
  array, and places all smaller (smaller than pivot)
  to left of pivot and all greater elements to right
  of pivot */
//int partition(int arr[], int low, int high)
//{
//    int pivot = arr[high]; // pivot
//    int i = (low - 1); // Index of smaller element
//
//    for (int j = low; j <= high - 1; j++) {
//
//        // If current element is smaller than or
//        // equal to pivot
//        if (arr[j] <= pivot) {
//
//            i++; // increment index of smaller element
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[i + 1], &arr[high]);
//    return (i + 1);
//}
int FirstQuickSort::partition1(int a[],int low,int high) {
    int pivot=a[low],p1=low+1,i,temp;

    for(i=low+1;i<=high;i++)
    {

        if(a[i]<pivot)
        {
            if(i!=p1)
            {
                temp=a[p1];
                a[p1]=a[i];
                a[i]=temp;
            }    p1++;
        }
    }

    a[low]=a[p1-1];
    a[p1-1]=pivot;
    cout << "partition1 used" << endl;
    return p1-1;
}

//int FirstQuickSort::partition(int *arr, int low, int high) {
//    int pivot = arr[high]; // pivot
//    int i = (low - 1); // Index of smaller element
//
//    for (int j = low; j <= high - 1; j++) {
//
//        // If current element is smaller than or
//        // equal to pivot
//        if (arr[j] <= pivot) {
//
//            i++; // increment index of smaller element
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[i + 1], &arr[high]);
//    return (i + 1);
//}
//Takes first element as pivot
//int partition1(int a[],int start,int end)
//
//{
//
//    int pivot=a[start],p1=start+1,i,temp;
//
//    for(i=start+1;i<=end;i++)
//    {
//
//        if(a[i]<pivot)
//        {
//            if(i!=p1)
//            {
//                temp=a[p1];
//                a[p1]=a[i];
//                a[i]=temp;
//            }    p1++;
//        }
//    }
//
//    a[start]=a[p1-1];
//    a[p1-1]=pivot;
//    cout << "partition1 used" << endl;
//    return p1-1;
//}
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */




