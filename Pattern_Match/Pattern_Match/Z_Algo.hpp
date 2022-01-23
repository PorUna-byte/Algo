//
//  Z_Algo.hpp
//  Pattern_Match
//
//  Created by PorUnaCabeza on 2021/12/15.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#ifndef Z_Algo_hpp
#define Z_Algo_hpp

#include <iostream>
#include <string>
using namespace std;
/*I strongly recommend you to read this webpage:http://www.utdallas.edu/~besp/demo/John2010/z-algorithm.htm
 Time:O(N) N is the length of str.
 Why linear time?
 because we never compare character less than R and with matching we increase R by one so there are at most N comparisons. In mismatch case, mismatch happen only once for each iteration of outer loop (because of which R stops), that’s another at most N comparison making overall linear complexity.
 */
void constructZarr(const string& str,int Zarr[]);
//Just a driver.
void match(const string& text,const string& pattern);
#endif /* Z_Algo_hpp */
