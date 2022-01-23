//
//  Z_Algo.cpp
//  Pattern_Match
//
//  Created by PorUnaCabeza on 2021/12/15.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "Z_Algo.hpp"
void constructZarr(const string& str,int Zarr[])
{
    int n=str.length();
    int L,R,k,count;
    L=R=0; //left & right border of interval.
    k=1; //current index
    count=0;
    while(k<n)
    {
        if(k>R)  //current index has past the right border(which means out of the interval)
        {
            //Zarr[k] must be computed explicitly
            count=0;
            while(count<n-k&&str[k+count]==str[0+count])
                count++;
            Zarr[k]=count;
            L=k;
            R=L+count-1;
        }
        else //current index is in a previously discovered substring.
        {
            if(Zarr[k-L]<R-k+1)
                Zarr[k]=Zarr[k-L];
            else //additional comparisons are needed
            {
                count=R-k+1;
                while(count<n-k&&str[k+count]==str[0+count])
                    count++;
                Zarr[k]=count;
                L=k;
                R=L+count-1;
            }
        }
        k++;
    }
}
void match(const string& text,const string& pattern)
{
    string concat=pattern+"$"+text;
    int Zarr[concat.length()];
    constructZarr(concat, Zarr);
    int m=(int)pattern.length();
    for(int i=m;i<concat.length();i++)
    {
        if(Zarr[i]==m)
            cout<<"At position: "<<i-m-1<<endl;
    }
}
