//
//  K_smallest.cpp
//  K_smallest
//
//  Created by PorUnaCabeza on 2021/12/6.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "K_smallest.hpp"
KeyType findMedian(KeyType subarr[],int n)
{
    sort(subarr,subarr+n);
    return subarr[n/2];
}
int Partition(KeyType *arr,int l,int r,KeyType piv)
{
    int i=l;
    int j=r;
    int k=l;
    for(;k<=r;k++)
        if(arr[k]==piv)
            break;
    swap(arr[k], arr[l]);
    while(i<j)
    {
        swap(arr[i], arr[j]);
        while(arr[i]<piv)
            i++;
        while(arr[j]>=piv)
            j--;
    }
    swap(arr[i], arr[r]);
    return i;
}
//resolve the T(n) to be O(n).
KeyType Ksmallest(KeyType* arr,int l,int r,int k)
{
    int n=r-l+1; //the length of the array
    if(k>0&&k<=n)
    {
        int groupNums=(n+4)/5; //each group contains 5 elements.
        int* median=new int[groupNums];
        int i=0;
        for(;i<n/5;i++) //build the median ,  O(n)
            median[i]=findMedian(arr+l+5*i, 5);
        if(5*i<n) //for the last group not full
        {
            median[i]=findMedian(arr+l+5*i, n%5);
            i++;
        }
        
        KeyType median_of_median=(i==1)?median[i-1]:  //T(n/5)
        Ksmallest(median, 0, groupNums-1, groupNums/2);
        int pos=Partition(arr, l, r, median_of_median);//O(n)
        delete[] median;
        if(pos-l+1==k)
            return median_of_median;
        else if(pos-l+1>k)
            return Ksmallest(arr, l, pos-1, k); //T(7n/10)
        else                                     //These two routine only has one will be called
            return Ksmallest(arr, pos+1, r, k-pos+l-1);//T(7n/10)
    }
    else
        return INT_MAX;
}
