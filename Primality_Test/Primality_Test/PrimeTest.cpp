//
//  PrimeTest.cpp
//  Primality_Test
//
//  Created by PorUnaCabeza on 2021/9/18.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "PrimeTest.hpp"
#include <time.h>
HugeInt Witness(HugeInt A,HugeInt i,HugeInt N)
{
    HugeInt X,Y;
    if(i==0)  //Here is the base
        return 1;
    X=Witness(A, i/2, N);
    if(X==0) //We can be sure that X is composite
        return 0;
    
    Y=(X*X)%N;        //theorem:If P is prime and 0<X<P, the only solutions to (X^2==1 mod P) are X==1 or X==P-1
    if(Y==1&&X!=1&&X!=N-1)
        return 0;
    if(i%2)   //choice Y randomly
        Y=(A*Y)%N;
    return Y;
}
bool IsPrime(HugeInt N) //N>3
{
    if(N==2||N==3)
        return true;
    else if (N==1)
        return false;
    srand(time(NULL));
    return Witness(random()%(N-3)+2, N-1, N)==1 ;
}
