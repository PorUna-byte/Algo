//
//  EggDrop.hpp
//  EggDrop_puzzle
/*
 The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.
 Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:
 …..An egg that survives a fall can be used again.
 …..A broken egg must be discarded.
 …..The effect of a fall is the same for all eggs.
 …..If an egg breaks when dropped, then it would break if dropped from a higher floor.
 …..If an egg survives a fall then it would survive a shorter fall.
 …..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.
 If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second-floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases?
 The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that the total number of trials are minimized.
 If the egg breaks after dropping from ‘xth’ floor, then we only need to check for floors lower than ‘x’ with remaining eggs as some floor should exist lower than ‘x’ in which egg would not break; so the problem reduces to x-1 floors and n-1 eggs.
 If the egg doesn’t break after dropping from the ‘xth’ floor, then we only need to check for floors higher than ‘x’; so the problem reduces to ‘k-x’ floors and n eggs.
 */
//  Created by PorUnaCabeza on 2021/12/7.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.


#ifndef EggDrop_hpp
#define EggDrop_hpp

#include <iostream>
using namespace std;
/*
k ==> Number of floors
n ==> Number of Eggs
eggDrop(n, k) ==> Minimum number of trials needed to find the critical
floor in worst case.
eggDrop(n, k) = 1 + min{max(eggDrop(n – 1, x – 1), eggDrop(n, k – x)), where x is in {1, 2, …, k}}
 Time:O(nk^2)
 Space:O(nk)
 */
int EggDrop(int n,int k);

//Another algorithm for egg droping puzzle,but has a better performance.
//For complete proof,please refer to the paper which is already in the same directory named eggold.pdf
//Time:O(nlogk)
//Space:O(1)
int EggDrop_Maxfloor(int n,int k);
#endif /* EggDrop_hpp */
