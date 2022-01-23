//
//  BMH.hpp
//  Pattern_Match
//
//  Created by PorUnaCabeza on 2021/12/13.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//
/*
 we will discuss the Boyer Moore pattern searching algorithm. Like KMP and Finite Automata algorithms, Boyer Moore algorithm also preprocesses the pattern.
 Boyer Moore is a combination of the following two approaches.
 1) Bad Character Heuristic
 2) Good Suffix Heuristic
 Both of the above heuristics can also be used independently to search a pattern in a text.These two heuristics can also be combined together to solve a pattern matching problem by using greatest offset suggested by the two heuristics at every step.

 Unlike the previous pattern searching algorithms, the Boyer Moore algorithm starts matching from the last character of the pattern.
 */
#ifndef BMH_hpp
#define BMH_hpp

#include <iostream>
#include <string>
#define NO_OF_CHAR 256
using namespace std;
/*
 The idea of bad character heuristic is simple. The character of the text which doesn’t match with the current character of the pattern is called the Bad Character. Upon mismatch, we shift the pattern until –
 1) The mismatch becomes a match
 2) Pattern P moves past the mismatched character.
 Time:O(M)
 */
void badCharHeu(int shift[],const string &pattern);

/*
 Let t be substring of text T which is matched with substring of pattern P. Now we shift pattern until :
 1) Another occurrence of t in P matched with t in T.
 2) A prefix of P, which matches with suffix of t
 3) P moves past t
 Time:O(M)
 */
void goodSuffixHeu(int shift[],const string& pattern);
/*
 Starting match from the last character of the pattern.
 when mismatch occurs,use the larger amount of shift recommended by badCharHeu and goodSuffixHeu.
 Time:O(M+N)
 */
void search(const string& text,const string& pattern);
#endif /* BMH_hpp */
