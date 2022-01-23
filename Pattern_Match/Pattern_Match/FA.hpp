//
//  FA.hpp
//  Pattern_Match
//
//  Created by PorUnaCabeza on 2021/12/13.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#ifndef FA_hpp
#define FA_hpp

#include <iostream>
#include <string>
#define NO_OF_CHARS 256
using namespace std;
//This method is used to construct Finite Automata and match the text.
/*
 How to construct a Finite Automata?
 1) Fill the first row. All entries in the first row are always 0 except the entry for the pat[0] character. For pat[0] character, we always need to go to state 1.
 2) Initialize lps as 0. lps for the first index is always 0.
 3) Do following for rows at index i = 1 to M. (M is the length of the pattern)
 …..a) Copy the entries from the row at index equal to lps.
 …..b) Update the entry for pat[i] character to i+1.
 …..c) Update lps “lps = TF[lps][pat[i]]” where TF is the 2D array which is being constructed.
 Time:O(M)
 How to match the text?
 Just imitate how a finite machine move.
 Time:O(N)
 */
//The total time is O(M+N) M is the length of pattern and N is the length of text.
void match_FA(const string& pattern,const string& text);
#endif /* FA_hpp */
