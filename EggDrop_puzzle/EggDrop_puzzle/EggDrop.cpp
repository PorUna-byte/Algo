//
//  EggDrop.cpp
//  EggDrop_puzzle
//
//  Created by PorUnaCabeza on 2021/12/7.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "EggDrop.hpp"
typedef struct state{
    int u=-1;
    int v=-1;
}State;
int EggDrop(int n,int k)
{
    int table[n+1][k+1];
    int count=INT_MAX;
    State states[n+1][k+1];
    for(int i=1;i<=n;i++)
    {
        table[i][0]=0;
        table[i][1]=1;
    }
    for(int j=1;j<=k;j++)
        table[1][j]=j;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            count=INT_MAX;
            for(int x=1;x<=j;x++)
            {
                if(count>1+max(table[i-1][x-1],table[i][j-x]))
                {
                    if(table[i-1][x-1]>table[i][j-x]) //broken
                    {
                        count=1+table[i-1][x-1];
                        states[i][j].u=i-1;
                        states[i][j].v=x-1;
                    }
                    else  //Not broken
                    {
                        count=1+table[i][j-x];
                        states[i][j].u=i;
                        states[i][j].v=j-x;
                    }
                }
            }
            table[i][j]=count;
        }
    }
    int i=n,j=k;
    int temp_u,temp_v;
    while(states[i][j].u!=-1)
    {
        if(states[i][j].u==i)
        cout<<"try floor "<<k-states[i][j].v<<"  ,Not broken"<<endl;
        else
        cout<<"try floor "<<states[i][j].v+1<<"  ,broken"<<endl;
        temp_u=states[i][j].u;
        temp_v=states[i][j].v;
        i=temp_u;
        j=temp_v;
    }
    return table[n][k];
}
int MaxFloor(int x,int n)
{
    int term=1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        term*=x-i+1;
        term/=i;
        sum+=term;
    }
    return sum;
}
int EggDrop_Maxfloor(int n,int k)
{
    int low=1,high=k,mid;
    while(low<high)
    {
        mid=(low+high)/2;
        if(MaxFloor(mid, n)<k)
            low=mid+1;
        else
            high=mid;
    }
    return low;
}
