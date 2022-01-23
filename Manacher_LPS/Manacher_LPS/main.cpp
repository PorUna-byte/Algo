//
//  main.cpp
//  Manacher_LPS
//
//  Created by PorUnaCabeza on 2021/12/16.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "Manacher_LPS.hpp"

int main(int argc, const char * argv[]) {
    LPS lps("babcbabcbaccba");
    lps.search();
    
    LPS lps1("abcbabcbabcba");
    lps1.search();
    
    LPS lps2("forgeeksskeegfor");
    lps2.search();
    
    LPS lps3("abacdfgdcaba");
    lps3.search();
    
    LPS lps4("abacdfgdcabba");
    lps4.search();
    
    LPS lps5("abacdedcaba");
    lps5.search();
    return 0;
}
