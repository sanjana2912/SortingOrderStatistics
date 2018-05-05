//
// Created by kavya on 5/4/2018.
//

#ifndef MENU_MEDIANOF3QUICKSORT_H
#define MENU_MEDIANOF3QUICKSORT_H

#include "GenerateInput.h"

class MedianOf3QuickSort {
public:
    static void quicksort(float *A, int lo, int hi);
    static int partition(float *A, int lo, int hi);
    static void swap_median(float *A, int lo, int hi);
    static void print_Array_median(float arr[], int size);
    static double quickSort(float *A, int lo, int hi);

};


#endif //MENU_MEDIANOF3QUICKSORT_H
