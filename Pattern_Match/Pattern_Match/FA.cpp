//
//  FA.cpp
//  Pattern_Match
//  It's just a viration of KMP ,I think.
//  Created by PorUnaCabeza on 2021/12/13.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "FA.hpp"
void match_FA(const string& pattern,const string& text)
{
    int M=(int)pattern.length();
    int TF[M+1][NO_OF_CHARS];
    int lps=0;
    memset(TF[0], 0, NO_OF_CHARS*sizeof(int));
    TF[0][pattern[0]]=1;
    for(int i=1;i<=M;i++)
    {
        for(int x=0;x<NO_OF_CHARS;x++)//Handle mismatch case.
            TF[i][x]=TF[lps][x];   //You need to figure out why this equation holds? hints:"longest prefix suffix".
        //Note that at this time,lps is the "longest prefix suffix" of "pattern[0,1,...i-1]"
        //The "longest prefix suffix" of "pattern[0,1,...i-1]c" is the same as "pattern[0,1,...lps-1]c".
        
        if(i<M)
        {
            TF[i][pattern[i]]=i+1;  //Handle match case.
            lps=TF[lps][pattern[i]];  //lps now updates to the "longest prefix suffix" of "pattern[0,1,...i]"
        }
    }
    int state=0;
    for(int x=0;x<text.length();x++)
    {
        state=TF[state][text[x]];
        if(state==M)
            cout<<"Location at "<<x-M+1<<endl;
    }
}
