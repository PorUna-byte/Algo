//
//  main.cpp
//  K_smallest
//
//  Created by PorUnaCabeza on 2021/12/6.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "K_smallest.hpp"
#include <time.h>
const int N=1000;
const int range=100000;
int main(int argc, const char * argv[]) {
    int* arr=new int[N];
    int* back=new int[N];
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        arr[i]=rand()%range;
        back[i]=arr[i];
    }
    sort(back, back+N);
    int k=3;
    while(k>0)
    {
        cin>>k;
        cout << k<<"'th smallest element is "
        << Ksmallest(arr, 0, N-1, k)<<'\t'<<back[k-1]<<endl;
    }
    return 0;
}
