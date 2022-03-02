//
//  main.cpp
//  Closest_point_pair
//
//  Created by PorUnaCabeza on 2022/2/25.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#include "closest_point_pair.hpp"

int main(int argc, const char * argv[]) {
    Point P[] = {{2, 3},{12,11}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n)<<endl;
    return 0;
}
