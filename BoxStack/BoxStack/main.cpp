//
//  main.cpp
//  BoxStack
//
//  Created by PorUnaCabeza on 2021/12/10.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "BoxStack.hpp"

int main(int argc, const char * argv[]) {
    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("The maximum possible height of stack is %d\n",
           solveBoxStack(arr, n));
    
    return 0;
}
