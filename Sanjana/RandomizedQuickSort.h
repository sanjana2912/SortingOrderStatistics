//
// Created by Sanjana on 21-04-2018.
//

#ifndef UNTITLED_RANDOMIZEDQUICKSORT_H
#define UNTITLED_RANDOMIZEDQUICKSORT_H
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;


class RandomizedQuickSort {
public:
    static int partition_r(int arr[], int low, int high);
    static int partition(int arr[], int low, int high);
    //void quickSort(int arr[], int low, int high);


};


#endif //UNTITLED_RANDOMIZEDQUICKSORT_H
