//
//  closest_point_pair.hpp
//  Closest_point_pair
//
/*
 Following are the detailed steps of a O(n (Logn)^2) algorithm.
 Input: An array of n points P[]
 Output: The smallest distance between two points in the given array.
 As a pre-processing step, the input array is sorted according to x coordinates.
 1) Find the middle point in the sorted array, we can take P[n/2] as middle point.
 2) Divide the given array in two halves. The first subarray contains points from P[0] to P[n/2]. The second subarray contains points from P[n/2+1] to P[n-1].
 3) Recursively find the smallest distances in both subarrays. Let the distances be dl and dr. Find the minimum of dl and dr. Let the minimum be d.
 4） From the above 3 steps, we have an upper bound d of minimum distance. Now we need to consider the pairs such that one point in pair is from the left half and the other is from the right half. Consider the vertical line passing through P[n/2] and find all points whose x coordinate is closer than d to the middle vertical line. Build an array strip[] of all such points.
 5) Sort the array strip[] according to y coordinates. This step is O(nLogn). It can be optimized to O(n) by recursively sorting and merging.
 6) Find the smallest distance in strip[]. This is tricky. From the first look, it seems to be a O(n^2) step, but it is actually O(n). It can be proved geometrically that for every point in the strip, we only need to check at most 7 points after it (note that strip is sorted according to Y coordinate).
 7) Finally return the minimum of d and distance calculated in the above step (step 6)
 */
//

#ifndef closest_point_pair_hpp
#define closest_point_pair_hpp

#include <iostream>
#include <math.h>
#include <float.h>
using namespace std;

// A divide and conquer program in C++
// to find the smallest distance from a
// given set of points.

// A structure to represent a Point in 2D plane
class Point
{
public:
    int x, y;
};

/* Following two functions are needed for library function qsort().
 Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */

// Needed to sort array of points
// according to X coordinate
int compareX(const void* a, const void* b);

// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b);

// A utility function to find the
// distance between two points
float dist(Point p1, Point p2);

// A Brute Force method to return the
// smallest distance between two points
// in P[] of size n
float bruteForce(Point P[], int n);

// A utility function to find
// minimum of two float values
float min(float x, float y);


// A utility function to find the
// distance between the closest points of
// strip of given size. All points in
// strip[] are sorted according to
// y coordinate. They all have an upper
// bound on minimum distance as d.
// Note that this method seems to be
// a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d);

// A recursive function to find the
// smallest distance. The array P contains
// all points sorted according to x coordinate
float closestUtil(Point P[], int n);

// The main function that finds the smallest distance
// This method mainly uses closestUtil()
float closest(Point P[], int n);
#endif
// This is code is contributed by rathbhupendra#endif /* closest_point_pair_hpp */
