//
//  Manacher_LPS.hpp
//  Manacher_LPS
//
//  Created by PorUnaCabeza on 2021/12/16.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#ifndef Manacher_LPS_hpp
#define Manacher_LPS_hpp

#include <iostream>
#include <string>
using namespace std;

class LPS{
private:
    string text;
    int centerPos;
    int centerRightPos;
    int currentPos;
    int imageCur;
    int *lps;
    int long_center;
    int long_length=0;
public:
    LPS(string text){
        this->text=text;
        lps=new int[2*text.length()+1];
        lps[0]=0;
        lps[1]=1;
        centerPos=1;
        centerRightPos=1;
        currentPos=2;
    }
    ~LPS(){
        delete lps;
    }
    /*
     Time:O(N) N is the length of text.
     why linear time?
     It only compares the character after centerRightPos ,and add 1 to centerRightPos for each comparison.
     So the total comparisons is O(N)
     Other sentence takes O(1) time for each outer iteration thus make total O(N) time.
     So the overall time is O(N+N)=O(N).
     */
    void search();
};
#endif /* Manacher_LPS_hpp */
