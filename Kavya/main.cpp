//
// Created by kavya on 4/22/2018.
//
#include <iostream>
#include "top_k_smallest_elements.h"
using namespace std;
// Driver program
int main() {
    float array[] = {5, 2, 45, 1, 32, 11, 9};
    int n = sizeof(array) / sizeof(array[0]);
    int k = 4;
    cout<<"The top "<<k<<" elements in the array are : \n";
    top_k_smallest_elements(array, n, k);
}