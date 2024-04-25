/*
# 1037. Valid Boomerang
*/
/*
Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.

A boomerang is a set of three points that are all distinct and not in a straight line.

 

Example 1:

Input: points = [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: points = [[1,1],[2,2],[3,3]]
Output: false
 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    // double calculateSlope(vector<int> v1,vector<int> v2){
    //      if(v1[0]==v2[0]){
    //         return numeric_limits<double>::infinity();
    //      }
    //      return static_cast<double>(v2[1] - v1[1]) / (v2[0] - v1[0]);
    // }
    // bool isBoomerang(vector<vector<int>>& points) {
    //   if (points[0] == points[1] || points[0] == points[2] || points[1] == points[2]) {
    //         return false;
    //     }

    //    double slope1=calculateSlope(points[0],points[1]);
    //    double slope2=calculateSlope(points[0],points[2]);
    //    double slope3=calculateSlope(points[1],points[2]);

    //   if (slope1 == slope2 || slope1 == slope3 || slope2 == slope3) {
    // return false;
    //   }
    //     return true;
    // }
    bool isBoomerang(vector<vector<int>>& points) {
       vector<int> v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        vector<int> v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        
        // Calculate the cross product of the vectors
        int crossProduct = v1[0] * v2[1] - v1[1] * v2[0];
        
        // If the cross product is zero, points are collinear
        return crossProduct != 0;
    }
};

int main(){

    vector<vector <int>> nums = {{1,1},{2,3},{3,2}};
    int k=2;

    Solution solution;
    bool score = solution.isBoomerang(nums);

    cout << score << endl;

    return 0;
}
