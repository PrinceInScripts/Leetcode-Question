

/*
# 1480. Running Sum of 1d Array
*/
/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
*/

#include <iostream>
#include <vector> 
#include<algorithm>
#include <limits.h>
#include<unordered_map>

using namespace std;

class Solution
{
public:

   vector<int> runningSum1(vector<int>& nums) {
     vector<int> ans(nums.size(),0);
     ans[0]=nums[0];
     for(int i=1;i<ans.size();i++){
         ans[i]=ans[i-1]+nums[i];
     }
      return ans;
    }
   vector<int> runningSum(vector<int>& nums) {
     for(int i=1;i<nums.size();i++){
         nums[i]+=nums[i-1];
     }
      return nums;
    }
};

int main()
{
  vector<int> nums = {1,2,3,4};

    Solution solution;
    vector<int> ans = solution.runningSum(nums);
   
   for(int el:ans){
    cout<<el<<" ";
   }
    return 0;
    
}
