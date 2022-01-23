//
//  BoxStack.hpp
//  BoxStack
//
//  Created by PorUnaCabeza on 2021/12/11.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//
/*
 Problem description:
 You are given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) and depth d(i) (all real numbers). You want to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base. It is also allowable to use multiple instances of the same type of box.
 
 Ans:
 1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of the original array. For simplicity, we consider width as always smaller than or equal to depth.
 2) Sort the above generated 3n boxes in decreasing order of base area.
 3) After sorting the boxes, the problem is same as LIS with following optimal substructure property.
 MSH(i) = Maximum possible Stack Height with box i at top of stack
 MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i).
 If there is no such j then MSH(i) = height(i)
 4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n
 Following is the implementation of the above solution. */

#ifndef BoxStack_hpp
#define BoxStack_hpp

#include <iostream>
using namespace std;
typedef struct box {
    int height;
    int width;
    int depth;
}Box;

int solveBoxStack(Box boxs[],int n);
#endif /* BoxStack_hpp */
