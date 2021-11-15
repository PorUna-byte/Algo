//
//  main.cpp
//  Primality_Test
//
//  Created by PorUnaCabeza on 2021/9/18.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "PrimeTest.hpp"

int main(int argc, const char * argv[]) {
    cout<<"42307 is prime? "<<endl<<(IsPrime(42307)==true?"true":"false")<<endl;
    cout<<"42217 is prime? "<<endl<<(IsPrime(42217)==true?"true":"false")<<endl;
    return 0;
}
