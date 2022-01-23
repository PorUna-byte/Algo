//
//  BoxStack.cpp
//  BoxStack
//
//  Created by PorUnaCabeza on 2021/12/11.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "BoxStack.hpp"
int compare(const void* p1,const void* p2)//if return value is smaller than 0,p1 stands in front of p2.so decreasing order by base area.
{
    return ((Box *)p2)->width*((Box *)p2)->depth-
    ((Box *)p1)->width*((Box *)p1)->depth;
}
int solveBoxStack(Box boxs[],int n)
{
    Box rotate[3*n];
    int index=0;
    for(int i=0;i<n;i++)  //We assume depth are greater or equal than width,which make sense since if not,we can rotate the stacking boxes to meet this constraint.
    {
        rotate[index].height=boxs[i].height;
        rotate[index].width=min(boxs[i].width, boxs[i].depth);
        rotate[index].depth=max(boxs[i].width, boxs[i].depth);
        index++;
        rotate[index].height=boxs[i].width;
        rotate[index].width=min(boxs[i].height, boxs[i].depth);
        rotate[index].depth=max(boxs[i].height, boxs[i].depth);
        index++;
        rotate[index].height=boxs[i].depth;
        rotate[index].width=min(boxs[i].width, boxs[i].height);
        rotate[index].depth=max(boxs[i].width, boxs[i].height);
        index++;
    }
    qsort(rotate, 3*n, sizeof(rotate[0]),compare);
    //Now is the same as LIS
    int MSH[3*n];
    int path[3*n];
    for(int i=0;i<3*n;i++)
    {
        MSH[i]=rotate[i].height;
        for(int j=0;j<i;j++)
        {
            if(MSH[j]+rotate[i].height>MSH[i]&&
               rotate[i].depth<rotate[j].depth&&
               rotate[i].width<rotate[j].width)
            {
                MSH[i]=MSH[j]+rotate[i].height;
                path[i]=j;
            }
        }
    }
    //find maximum in MSH[] as result
    int maxmsh=MSH[0];
    for(int i=0;i<3*n;i++)
        maxmsh=max(maxmsh, MSH[i]);
    
    return maxmsh;
}
