

/*
# 34. Find First and Last Position of Element in Sorted Array
*/
/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
   vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
       int lo=0;
       int hi=n-1;

       vector<int> ans={-1,-1};
       
       if(n==0) return ans;

       while(lo<=hi){
          int mid=lo+(hi-lo)/2;

          if(nums[mid]==target){
            
                if(mid==0 ||nums[mid-1]!=target){
                    ans[0]=mid;
                    break;
                } else {
                  hi=mid-1;
                }
          } 
          else if(nums[mid]<target) lo=mid+1;
          else if(nums[mid]>target) hi=mid-1;
       }
       lo=0;
       hi=n-1;
       while(lo<=hi){
          int mid=lo+(hi-lo)/2;

          if(nums[mid]==target){
            
                if(mid==n-1 ||nums[mid+1]!=target){
                    ans[1]=mid;
                    break;
                } else{
                    lo=mid+1;
                }
          } 
          else if(nums[mid]<target) lo=mid+1;
          else if(nums[mid]>target) hi=mid-1;
       }

       return ans;
    }
   

};

int main()
{
    vector<int> nums={5,7,7,8,8,10};
    int target=8;

    Solution solution;
    vector<int> ans = solution.searchRange(nums,target);
    for(auto el:ans){
        cout<<el<<endl;
    }

    return 0;
    
}
