//
//  KMP.hpp
//  KMP
//  The full name of KMP is knuth-morris pattern,which is an efficient string matching algorithm.

//  Created by PorUnaCabeza on 2021/11/14.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#ifndef KMP_hpp
#define KMP_hpp

#include <iostream>
#include <string>
using namespace std;

/*
  Caculate the next[j] that is the next position of pattern to try when pattern[j] does not match.
  Time complexity:O(l^2) l is the length of pattern
 */
int* Cal_next(const string& pattern);

/*
  match the pattern with text, return the first occurrence of pattern in text.
  if no such occurrence return -1.
  tiem complexity O(|text|+|pattern|)
 */
int match_KMP(const string& pattern,const string& text);
#endif /* KMP_hpp */
