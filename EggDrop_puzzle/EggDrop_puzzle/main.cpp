//
//  main.cpp
//  EggDrop_puzzle
//
//  Created by PorUnaCabeza on 2021/12/7.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "EggDrop.hpp"

int main(int argc, const char * argv[]) {
    int n = 2, k = 100;
    cout << "\nMinimum number of trials "
    "in worst case with " << n<< " eggs and "<< k<<
    " floors is "<<endl<< EggDrop(n, k)<<endl;
    
    cout<<EggDrop_Maxfloor(n, k)<<endl;
    return 0;
}
