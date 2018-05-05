//
// Created by kavya on 5/4/2018.
//

#include "MedianOf3QuickSort.h"

#include <utility>
#include <limits>
#include <random>

using namespace std;

double MedianOf3QuickSort::quickSort(float *A, int lo, int hi){
    int n = hi + 1;
    auto start = get_time::now();
    MedianOf3QuickSort::quicksort(A, lo, hi);
    auto end = get_time::now();
    auto diff = end - start;
    double time = chrono::duration_cast<chrono::nanoseconds>(diff).count();
    printf("\nSorted array: \n");
    print_Array_median(A,n);
    cout<<"Elapsed time is :  "<< time/1000000 <<" ms "<<endl;
    float runtime= time/1000000;
    GenerateInput::write_runtime_to_file(n, runtime, "quicksort_median");
    return runtime;
}

void MedianOf3QuickSort::print_Array_median(float arr[], int size)
{
    ofstream file2;
    string timestamp = GenerateInput::get_date();
    string path = GenerateInput::GetCurrentWorkingDir();
    path +="\\output\\";
    file2.open(path+"quicksort_median_"+timestamp+".txt");
    for (int i = 0; i < size; i++) {
        file2 << arr[i] << "\n";
        cout << arr[i]<<"\t";
    }
    cout << "\nOutput was written to file!!\n";
    file2.close();
}

void MedianOf3QuickSort::quicksort(float *A, int lo, int hi)
{
    if (hi <= lo)
        return;

    swap_median(A, lo, hi);

    int mid = partition(A, lo, hi);

    quicksort(A, lo, mid-1);
    quicksort(A, mid+1, hi);
}

int MedianOf3QuickSort::partition(float *A, int lo, int hi)
{
    int i = lo - 1;

    for (int j = lo; j < hi; j++)
        if (A[j] < A[hi])
            swap(A[++i], A[j]);

    swap(A[++i], A[hi]);

    return i;
}

void MedianOf3QuickSort::swap_median(float *A, int lo, int hi)
{
    int mid = (hi + lo) / 2;

    if (A[mid] > A[lo] && A[mid] < A[hi]) {
        swap(A[mid], A[hi]);
        return;
    }

    if (A[lo] > A[mid] && A[lo] < A[hi]) {
        swap(A[lo], A[hi]);
        return;
    }
}