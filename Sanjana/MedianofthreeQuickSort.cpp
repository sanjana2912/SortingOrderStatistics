//
// Created by Sanjana on 24-04-2018.
//

#include "MedianofthreeQuickSort.h"
#include "RandomizedQuickSort.h"

int MedianofthreeQuickSort::calc_median (int *arr)
{
    srand ( time(NULL) ); //initialize the random seed


    int arr_len= sizeof(arr);
    int a = -1, b = -1, c = -1;
    int first,second,third;
    a = rand() % arr_len;
    b = rand() % arr_len;

    while(a==b){
        b = rand() % arr_len;
    }

    c = rand() % 4;
    while(c==a or c==b){
        c = rand() % arr_len;
    }

   first = arr[a] ;
   second = arr[b] ;
   third = arr[c] ;

    int median = max(min(first,second), min(max(first,second), third));
 return median;

}



int MedianofthreeQuickSort::partition_median(int *arr, int low, int high) {
    int pivot = calc_median(arr); // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {

            i++;
            RandomizedQuickSort::swap(&arr[i], &arr[j]);
        }
    }
    RandomizedQuickSort::swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}