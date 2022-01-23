//
//  main.cpp
//  Word_wrap
//
//  Created by PorUnaCabeza on 2021/12/10.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "Word_wrap.hpp"

int main(int argc, const char * argv[]) {
    string words[]={"Geeks","for", "Geeks", "presents","word","wrap","problem"};
    int* path=solveWordwrap(words, 7,15);
    print_words(words,7, path);
    return 0;
}
