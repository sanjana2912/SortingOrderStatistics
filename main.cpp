#include <iostream>
#include "Num.h"

using namespace std;

int main()
{
  kthSmallest n();

  int arr[] = {10, 1, 4, 0, 5, 6, 7, 2, 8, 9};
  int size = sizeof(arr)/sizeof(arr[0]), k = 3;
  cout << "K\'th smallest element is " << kthSmallest::calcKthSmallest(arr, 0, size-1, k);

  return 0;
}