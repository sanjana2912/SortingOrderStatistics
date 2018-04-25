//
// Created by kavya on 4/22/2018.
//

#include <iostream>
using namespace std;
void swap(float array[],int i ,int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void max_heapify(float array[], int i, int n)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if(left < n){
        if(array[left] > array[i])
            largest = left;
    }
    if(right < n){
        if(array[right] > array[largest])
            largest = right;
    }
    if(largest != i){
        swap(array, i, largest);
        max_heapify(array, largest, n);
    }
}
void print(float array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << "\n";
}
void top_k_smallest_elements(float array[], int n, int k)
{
    int i;
    float temp_array[k];
    for( i = 0; i < k; i++)
        temp_array[i] = array[i];

    for( i = (k-2)/2; i >= 0; i--)
        max_heapify(temp_array, i, k);

    for( i = k; i < n; i++)
    {
        if(temp_array[0] > array[i]){
            temp_array[0] = array[i];
            max_heapify(temp_array, 0, k);
        }
    }
    print(temp_array, k);
}