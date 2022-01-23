//
//  K_smallest.hpp
//  K_smallest
//Given an array and a number k where k is smaller than the size of the array, we need to find the k’th smallest element in the given array.
//  Created by PorUnaCabeza on 2021/12/6.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#ifndef K_smallest_hpp
#define K_smallest_hpp

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef int KeyType;
//partition the arr[l...r] using pivot piv(which must be in the arr)
//return the index of piv.
//O(n)
int Partition(KeyType *arr,int l,int r,KeyType piv);
// A simple function to find median of subarr[].  This is called
// only for an array of size 5 in this program
//O(1)
KeyType findMedian(KeyType subarr[],int n);
//find the k smallest element in arr[l...r].
//In recursive fashion.
//O(n)
KeyType Ksmallest(KeyType* arr,int l,int r,int k);
    
#endif /* K_smallest_hpp */
