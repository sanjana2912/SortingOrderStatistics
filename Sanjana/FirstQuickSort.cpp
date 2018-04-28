//
// Created by Sanjana on 21-04-2018.
//
#include "FirstQuickSort.h"
//
// Created by Sanjana on 20-04-2018.
//

using namespace std;

int FirstQuickSort::partition1(int a[],int first,int last) {
//initializing the pivot as the first element and then putting it in rightful position
    int pivot=a[first],next=first+1,i,temp;

    for(i=first+1;i<=last;i++)
    {
        if(a[i]<pivot)
        {
            if(i!=next)
            {
                temp=a[next];
                a[next]=a[i];
                a[i]=temp;
            }    next++;
        }
    }

    a[first]=a[next-1];
    a[next-1]=pivot;
    return next-1;
}




