

/*
# 233. Product of Array Except Self
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
using namespace std;

class Solution
{
public: 
  
     
     vector<int> productExceptSelf(vector<int>& nums) {
      int n=nums.size();

      vector<int> result(n,1);

      int prefix=1;
      for(int i=0;i<n;i++){
        result[i]*=prefix;
        prefix*=nums[i];
      }

      int suffix=1;
      for(int i=n-1;i>=0;i--){
        result[i]*=suffix;
        suffix*=nums[i];
      }

      return result;

       
    }
    //  vector<int> productExceptSelf(vector<int>& nums) {
    //   int n=nums.size();

    //   vector<int> prefix(n,1);
    //   vector<int> suffix(n,1);

    //   for(int i=1;i<n;i++){
    //     prefix[i]=prefix[i-1]*nums[i-1];
    //   }
    //   for(int i=n-2;i>=0;i--){
    //     suffix[i]=suffix[i+1]*nums[i+1];
    //   }
    //   vector<int> result(n,1);
    //   for(int i=0;i<n;i++){
    //      result[i]=prefix[i]*suffix[i];
    //   }

    //   return result;

       
    // }
     
    //  vector<int> productExceptSelf(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> ans(n,1);
    //     for(int i=0;i<n;i++){
    //         int prod=1;
    //         for(int j=0;j<n;j++){
    //             if(i==j) continue;
    //             else {
    //                 prod*=nums[j];
    //             }
    //         }
    //         ans[i]=prod;
    //     }

    //     return ans;
       
    // }

};

int main()
{
    vector<int> nums = {-1,1,0,-3,3};
 

    Solution solution;
    vector<int> ans = solution.productExceptSelf(nums);

    for(int num:ans){
        cout<<num<<" ";
    }

    return 0;
}
