//
//  van_Emde_Boas.cpp
//  van_Emde_Boas
//
//  Created by PorUnaCabeza on 2022/2/1.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#include "van_Emde_Boas.hpp"
VEB::VEB(int u):u(u){
    if(u>=4)
    {
        int u_up = 1 << ((log2(u) / 2) > (int)(log2(u) / 2) ? (int)(log2(u) / 2) + 1 : (int)(log2(u) / 2));
        int u_down = 1 << ((int)(log2(u) / 2));
        summary=new VEB(u_up);
        cluster = (VEB **)new VEB*[u_up]; //The size of cluster is u_up
        for (int i = 0; i < u_up; i++)
        {
            cluster[i]=new VEB(u_down); //Cluster[i]'s u is u_down
        }
    }
}
VEB::~VEB()
{
    delete summary;
    for(int i=0;i<sizeof(cluster)/sizeof(VEB*);i++)
        delete cluster[i];
    delete[] cluster;
}
bool VEB::is_Member(int x)
{
    if (x == min || x == max)
        return true;
    else if (u == 2)
        return false;
    else
        return cluster[high(x)]->is_Member(low(x));
}
int VEB::successor(int x)
{
    if (u == 2) //basic case
    {
        if (x == 0 && max == 1)
            return 1;
        else
            return NILNUM;
    }
    else if (min != NILNUM && x < min)
        return min;
    else
    {
        int max_low = cluster[high(x)]->max;
        if (max_low != NILNUM && low(x) < max_low) //successor lies in the same cluster as x
         {
            int offset = cluster[high(x)]->successor(low(x));
            return index(high(x), offset);
        }
        else //successor lies in other cluster or not exist at all
        {
            int succ_cluster = summary->successor(high(x));
            if (succ_cluster == NILNUM)
                return NILNUM;
            else
            {
                int offset = cluster[succ_cluster]->min;
                return index(succ_cluster, offset);
            }
        }
    }
}
int VEB::predecessor(int x)
{
    if (u == 2)
    {
        if (x == 1 && min == 0)//base case
            return 0;
        else
            return NILNUM;
    }
    else if (max != NILNUM && x > max)
        return max;
    else
    {
        int min_low = cluster[high(x)]->min;
        if (min_low != NILNUM && low(x) > min_low) //In x's cluster
        {
            int offset = cluster[high(x)]->predecessor(low(x));
            return index(high(x), offset);
        }
        else
        { //在前一个簇中找
            int pred_cluster = summary->predecessor(high(x));
            if (pred_cluster == NILNUM)
            {
                if (min != NILNUM && x > min)
                    //special case,since the min of this VEB does not appear in any cluster of this VEB
                    return min;
                else
                    return NILNUM;
            }
            else
            {
                int offset =cluster[pred_cluster]->max;
                return index(pred_cluster, offset);
            }
        }
    }
}
void VEB::empty_insert(int x)
{
    min=max=x;
}
void VEB::insert(int x)
{
    if (min == NILNUM)        //when itself is an empty cluster
        empty_insert(x);
    else
    {
        if (x < min)  //x becomes the new min,and the old min should be inserted.
            swap(x, min);
        if (u > 2)
        {
            if (cluster[high(x)]->min == NILNUM)
                //when the inserted subcluster is empty,we need to update summary
            {
                summary->insert(high(x));
                cluster[high(x)]->empty_insert(low(x));
            }
            else
                cluster[high(x)]->insert(low(x));
        }
        if (x > max)
            max = x;
    }
}
void VEB::delete_(int x)
{
    if (min == max)        //base case
        max = min = NILNUM;
    else if (u == 2)
    {
        if (x == 0)
            min = 1;
        else
            min = 0;
        max = min;
    }
    else
    {
        if (x == min)
            //when we delete the min,we should find the second min in subcluster and assign its value to the new min and delete the second min in subcluster,because the min does not appear in any subclusters.
        {
            int first_cluster = summary->min;
            int x = index(first_cluster,cluster[first_cluster]->min);
            min = x;
        }
        cluster[high(x)]->delete_(low(x));  //:S2,delete x from subcluster recursively
        //if S1 fuction call happens,then this recursion only takes constant time.
        if (cluster[high(x)]->min == NILNUM) //After deletion,the subcluster may become empty
        {
            summary->delete_(high(x)); //:S1 ,if this recursion happens,then S2 takes constant time
            if (x == max)
            {
                int summary_max = summary->max;
                if (summary_max == NILNUM)
                    max = min;
                else
                    max = index(summary_max,cluster[summary_max]->max);
            }
        }
        else if (x == max)
        {
            max = index(high(x),cluster[high(x)]->max);
        }
    }
}
int VEB::high(int x)
{
    return x / (1 << ((int)(log2(u) / 2)));
}
int VEB::low(int x)
{
    return x % (1 << ((int)(log2(u) / 2)));
}
int VEB::index(int x, int y)
{
    return x * (1 << ((int)(log2(u) / 2))) + y;
}
