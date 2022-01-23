//
//  Word_wrap.hpp
//  Word_wrap
//
//  Created by PorUnaCabeza on 2021/12/10.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//
/*
 Given a sequence of words, and a limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly. Assume that the length of each word is smaller than the line width.
 The word processors like MS Word do task of placing line breaks. The idea is to have balanced lines. In other words, not have few lines with lots of extra spaces and some lines with small amount of extra spaces.
 The extra spaces includes spaces put at the end of every line except the last one.
 The problem is to minimize the following total cost.
 Cost of a line = (Number of extra spaces in the line)^2
 Total Cost = Sum of costs for all lines
 
 For example, consider the following string and line width M = 15
 "Geeks for Geeks presents word wrap problem"
 
 Following is the optimized arrangement of words in 3 lines
 Geeks for Geeks
 presents word
 wrap problem
 
 The total extra spaces in line 1, line 2 and line 3 are 0, 2 and 3 respectively.
 So optimal value of total cost is 0 + 2*2 + 3*3 = 13 */
#ifndef Word_wrap_hpp
#define Word_wrap_hpp

#include <iostream>
using namespace std;

#define INF INT_MAX
/*
 Using Dynamic Algorithm to solve this problem.
 The following Dynamic approach strictly follows the algorithm given in solution of Cormen book. First we compute costs of all possible lines in a 2D table line_cost[][]. The value line_cost[i][j] indicates the cost to put words from i to j in a single line where i and j are indexes of words in the input sequences. If a sequence of words from i to j cannot fit in a single line, then line_cost[i][j] is considered infinite (to avoid it from being a part of the solution). Once we have the line_cost[][] table constructed, we can calculate total cost using following recursive formula. In the following formula, total_cost[j] is the optimized total cost for arranging words from 1 to j.
 
 total_cost[j]={                  0                           if j=0
               { min(total_cost[i-1]+line_cost[i][j]) 1<=i<=j if j>0
 
 Time:O(n^2)
 Space:O(n^2)
 */
int* solveWordwrap(string words[],int n,int line_width);

void print_words(string words[],int n,int* path);
#endif /* Word_wrap_hpp */
