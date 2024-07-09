

/*
# 219. Contains Duplicate II
*/
/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105


*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<regex>
using namespace std;

class Solution {
public:   
      bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
           if(map.find(nums[i])!=map.end()){
              if(abs(map[nums[i]]-i)<=k) return true;
              else map[nums[i]]=i;
           } else {
                map[nums[i]]=i;
           }
        }
       
        return false;
        

      } 
      
};


int main(){
   vector<int> nums={1,0,1,1};
   int k=1;
   Solution solution; 
   bool ans=solution.containsNearbyDuplicate(nums,k);

    
    cout<<ans;

    return 0;
}
