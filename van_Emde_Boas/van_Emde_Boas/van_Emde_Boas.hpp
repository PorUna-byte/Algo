//
//  van_Emde_Boas.hpp
//  van_Emde_Boas
/*
 Here is Van-Emde-Boas tree
 u is the scope of data.
 Time complexity:Insert,Delete,Predecessor,Successor,Member in O(lglgu)
 Space Complexity:O(u)
 Please refer to 'Introduction to Algorithms' for more details
 */
//  Created by PorUnaCabeza on 2022/2/1.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#ifndef van_Emde_Boas_hpp
#define van_Emde_Boas_hpp

#include <iostream>
#include <math.h>
#define NILNUM -1
using namespace std;
//This class represents a VEB node
class VEB
{
public:
    int max=NILNUM;
    int min=NILNUM;
    int u; //u=2^k,k is a non-negative integer
    VEB *summary=nullptr;
    VEB **cluster=nullptr;
    //construct a VEB node with scope u
    VEB(int u);
    //free space
    ~VEB();
    //query if x is a member of the VEB
    bool is_Member(int x);
    //find the successor of x in the VEB,x need not to be in this VEB.
    int successor(int x);
    //find the predecessor of x in the VEB,x need not to be in this VEB.
    int predecessor(int x);
    //Insert x into the VEB
    void insert(int x);
    //delete x from the VEB
    void delete_(int x);
private:
    int high(int x);
    int low(int x);
    int index(int x,int y);
    void empty_insert(int x);
};
#endif /* van_Emde_Boas_hpp */
