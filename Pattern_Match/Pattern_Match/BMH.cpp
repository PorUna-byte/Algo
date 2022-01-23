//
//  BMH.cpp
//  Pattern_Match
//
//  Created by PorUnaCabeza on 2021/12/13.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "BMH.hpp"
void badCharHeu(int shift[],const string &pattern)
{
    int m=(int)pattern.length();
    for(int i=0;i<NO_OF_CHAR;i++)
        shift[i]=-1;
    for(int i=0;i<m;i++)
        shift[pattern[i]]=i;
}
void goodSuffixHeu(int shift[],const string& pattern)
{
    memset(shift, 0, sizeof(int)*NO_OF_CHAR);
    int m=(int)pattern.length();
    int bpos[m+1];
    int i=m,j=m+1;
    bpos[i]=j;
    while(i>=0)
    {
        if(j<=m&&pattern[i-1]!=pattern[j-1])
        {
            if(shift[j]==0)
                shift[j]=j-i;
            j=bpos[j];
        }
        else
        {
            i--;j--;
            bpos[i]=j;
        }
    }
    j=bpos[0];
    i=0;
    while(i<m)
    {
        if(shift[i]==0)
            shift[i]=j;
        if(i==j)
            j=bpos[j];
        i++;
    }
}
void search(const string& text,const string& pattern)
{
    int shift_bad[NO_OF_CHAR];
    int shift_good[NO_OF_CHAR];
    badCharHeu(shift_bad, pattern);
    goodSuffixHeu(shift_good, pattern);
    int offset=0;
    int m=(int)pattern.length();
    int n=(int)text.length();
    int i=m-1;
    while(offset+m<=n)
    {
        i=m-1;
        while(pattern[i]==text[i+offset])
            i--;
        if(i<0)
        {
            cout<<"At position "<<offset<<endl;
            cout<<"BadChar Heuristic:"<<1<<'\t'<<"GoodSuffix Heuristic:"<<shift_good[0]<<endl;
            offset+=shift_good[0];
        }
        else
        {
            cout<<"BadChar Heuristic:"<<max(1,i-shift_bad[text[i+offset]])<<'\t'<<"GoodSuffix Heuristic:"<<shift_good[i+1]<<endl;
            offset+=max(shift_good[i+1],i-shift_bad[text[i+offset]]);
        }
    }
}
