#pragma once

class quickSort
{
  //private:
  //int n;
  
  public:
	void heapify(float arr[], int n, int i);

	void buildHeap(float arr[], int n);

	void heapSort(float arr[], int n);

	void printArray(float arr[], int n);
};
