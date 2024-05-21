

/*
# 1. Two Sum
*/
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
0 <= k < n
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    // 1 Way Brute force
    // vector<int> twoSum(vector<int>& nums, int target) {
          
    //       for(int i=0;i<nums.size();i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             if(nums[i]+nums[j]==target){
    //                 return {i,j};
    //             }
    //         }
    //       }
    // }

    // 2 way Using copy
    /* 
     vector<int> twoSum(vector<int>& nums, int target) {
          
        vector<int> sortedArray(nums.begin(),nums.end());
        sort(sortedArray.begin(),sortedArray.end());

        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int sum=sortedArray[left]+sortedArray[right];


            if(target==sum){
                vector<int> ans;
                for(int i=0;i<nums.size();i++){
                    if(nums[i]==sortedArray[left] || nums[i]==sortedArray[right]){
                        ans.push_back(i);
                    }
                }
                return ans;
            } else if(target>sum) right--;
            else left++;
        }
    }
    */

   //3 way 
    vector<int> twoSum(vector<int>& nums, int target) {
        
    }

};

int main()
{
    vector<int> nums = {3,2,4};
    int target=6;

    Solution solution;
    vector<int> ans = solution.twoSum(nums,target);

    for(int num:ans){
        cout<<num<<" ";
    }

    return 0;
}
