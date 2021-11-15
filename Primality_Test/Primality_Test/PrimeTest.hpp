//
//  PrimeTest.hpp
//  Primality_Test
//
//  Created by PorUnaCabeza on 2021/9/18.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#ifndef PrimeTest_hpp
#define PrimeTest_hpp
#define HugeInt unsigned int
#include <stdio.h>
#include <iostream>

using namespace std;
/*
 if Witness does not return 1, N is definitely not a prime
 Do this by computing A^i mod N and looking for non-trival square roots
 of 1 along the way.We are assuming very large numbers.
 */
HugeInt Witness(HugeInt A,HugeInt i,HugeInt N);

/*
 Test if N>=3 is prime using one value of A. Repeat this procedure as many times as needed for desired error rate.
 */
bool IsPrime(HugeInt N);
#endif /* PrimeTest_hpp */
