

/*
# 137.Single Number II
*/
/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:   
   
    
   
   int singleNumber(vector<int>& nums) {
       int n=nums.size();
       int ans=0;
       for(int i=0;i<32;i++){
          int sum=0;
          for(int num:nums){
            sum+=(num>>i) & 1;
          }
          sum%=3;
          ans|=(sum<<i);
       }
       return ans;

    }
   int singleNumber1(vector<int>& nums) {
       int n=nums.size();
       unordered_map<int,int> map;
       for(int num:nums){
          map[num]++;
       }
       for(auto& num:map){
          if(num.second==1) return num.first;
       }
       return -1;

    }
    
    
    
   
};


int main(){
    vector<int> arr={2,2,3,2};
   
    
    Solution solution; 
    int ans=solution.singleNumber(arr);

    
    cout<<ans;

    return 0;
}
