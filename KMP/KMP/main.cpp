//
//  main.cpp
//  KMP
//
//  Created by PorUnaCabeza on 2021/11/14.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "KMP.hpp"
int main(int argc, const char * argv[]) {
    string text="aaaababbaabbaaaabaaaaab";
    string pattern="aaaaab";
    cout<<"the first occurrence of "<<pattern<<" in "<<text<<" is :"<<match(pattern, text)<<endl;
    return 0;
}
