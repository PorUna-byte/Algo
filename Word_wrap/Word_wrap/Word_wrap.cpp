//
//  Word_wrap.cpp
//  Word_wrap
//
//  Created by PorUnaCabeza on 2021/12/10.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "Word_wrap.hpp"
#include <stack>
int* solveWordwrap(string words[],int n,int line_width)
{
    int extra[n+1][n+1];
    int line_cost[n+1][n+1];
    int total_cost[n+1];
    int *path=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        extra[i][i]=line_width-(int)words[i-1].length();
        for(int j=i+1;j<=n;j++)
            extra[i][j]=extra[i][j-1]-1-(int)words[j-1].length();
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            if(extra[i][j]<0)
                line_cost[i][j]=INF;
            else if(j==n)  //ignore the cost of last line,this makes sense since the last line does not necessarily full.
                line_cost[i][j]=0;
            else
                line_cost[i][j]=extra[i][j]*extra[i][j];
        }
    total_cost[0]=0;
    for(int i=1;i<=n;i++)
    {
        total_cost[i]=INF;
        for(int j=1;j<=i;j++)
        {
            if(total_cost[j-1]!=INF&&line_cost[j][i]!=INF&&
            total_cost[i]>total_cost[j-1]+line_cost[j][i])
            {
              total_cost[i]=total_cost[j-1]+line_cost[j][i];
                path[i]=j;
            }
        }
    }
    return path;
}
void print_words(string words[],int n,int* path){
    stack<int> sta;
    while(path[n]!=1)
    {
        sta.push(n);
        n=path[n]-1;
    }
    sta.push(n);
    int index_from=1;
    int index_end;
    while(!sta.empty())
    {
        index_end=sta.top();
        sta.pop();
        for(int i=index_from;i<=index_end;i++)
            cout<<words[i-1]<<" ";
        cout<<endl;
        index_from=index_end+1;
    }
}
