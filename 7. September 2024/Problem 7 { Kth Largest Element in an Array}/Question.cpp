

/*
# 215. Kth Largest Element in an Array
*/

/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

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
#include<queue>
using namespace std;

class Solution {
public:  
    
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int,vector<int>,greater<int>> pq;
        
         for( int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
         }

         return pq.top();
    }   
};


int main(){
    
    vector<int> original={10,20,-4,6,18,2,105,118};
    Solution solution; 
    int ans= solution.findKthLargest(original,3);
    
   cout<<ans;

}
