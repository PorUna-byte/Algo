//
//  KMP.cpp
//  KMP
//
//  Created by PorUnaCabeza on 2021/11/14.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "KMP.hpp"

int* Cal_next(const string& pattern)
{
    int* next=new int[pattern.length()];
    memset(next,0,sizeof(int)*pattern.length());
    next[0]=-1;
    next[1]=0;
    for(int j=1;j<pattern.length();j++)
    {
        int k=next[j];
        while(pattern[j]!=pattern[k]&&k!=-1)   //next[j+1]=next[next...next[j]]+1 iff pattern[j]==pattern[next[next...next[j]]].if there is no such matching ,just start from position zero.
            k=next[k];
        next[j+1]=k+1;  //if k==-1, this also holds.
        int m=k+1;
        if(m!=-1&&pattern[j+1]==pattern[m])
            m=next[m];
        next[j+1]=(m==-1?0:m);
    }

    return next;
}
int match(const string& pattern,const string& text)
{
    int* next=Cal_next(pattern);
    int i=0,j=0;
    while(j!=pattern.length()&&i!=text.length())
    {
        if(text[i]==pattern[j]) //match, try next position of both
        {
            i++;j++;
        }
        else if(j==0)
        {
            i++;  //if j is zero,and pattern[0]!=text[i], shift pattern right by one step this is equivalent to i++,fix j.
        }
        else
            j=next[j];  //if j is non-zero ,try position next[j] of pattern when keep i fixed
    }
    if(j==pattern.length())
        return i-(int)pattern.length();
    else
        return -1;
}
