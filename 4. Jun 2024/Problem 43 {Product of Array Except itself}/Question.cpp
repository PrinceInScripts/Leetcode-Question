

/*
# 238. Product of Array Except Self
*/
/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
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
  vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
      int prod=1;
      int prod2=1;
      int noz=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0) noz++;
        prod*=nums[i];
        if(nums[i]!=0) prod2*=nums[i]; 
    }
    if(noz>1) prod2=0;
    for(int i=0;i<n;i++){
       if(nums[i]==0) nums[i]=prod2;
      else nums[i]=prod/nums[i];
    }
    return nums;
    }
};

int main()
{
  vector<int> nums = {1,2,3,4};

    Solution solution;
    vector<int> ans = solution.productExceptSelf(nums);
   
   for(int el:ans){
    cout<<el<<" ";
   }
    return 0;
    
}
