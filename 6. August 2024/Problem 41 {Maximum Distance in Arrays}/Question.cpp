

/*
# 624. Maximum Distance in Arrays
*/
/*
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
 

Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:  
    
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest=arrays[0][0];
        int biggest=arrays[0].back();
        int maxDistance=0;
        for(int i=1;i<arrays.size();i++){
            maxDistance=max(maxDistance,abs(biggest-arrays[i][0]));
            maxDistance=max(maxDistance,abs(smallest-arrays[i].back()));
            biggest=max(biggest,arrays[i].back());
            smallest=min(smallest,arrays[i][0]);
        }
        return maxDistance;
    }   
};


int main(){
    vector<vector<int>> arrays={{1,2,3},{4,5},{1,2,3}};
    Solution solution; 
    int ans= solution.maxDistance(arrays);
    
   cout<<ans;
    return 0;

}
