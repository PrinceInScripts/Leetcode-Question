

/*
# 33.  Search in Rotated Sorted Array
*/
/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int lo=0;
       int hi=n-1;
       int pivot=-1;

       if(n==1){
         if(nums[0]==target) return 0;
         else return -1;
       }

       if(n==2){
        if(target==nums[0]) return 0;
        else if(target==nums[1]) return 1;
        else return -1;
       }

       //Find out pivot
       while(lo<hi){
        int mid=lo+(hi-lo)/2;
        
        if(nums[mid]>nums[hi]){
            lo=mid+1;
        } else hi=mid;
       }

       pivot=lo;  
       
      //Find out index with pivot
      lo=0;
      hi=n-1;

      if(target>nums[hi] && target>nums[pivot])  hi=pivot-1;
      else lo=pivot;

      while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(nums[mid]==target){
            return mid;
        } else if(nums[mid]>target) hi=mid-1;
        else lo=mid+1;
      }
      

      return -1;

    }

};

int main()
{
   vector<int> nums={1,3,5};
   int target=1;
    

    Solution solution;
   int ans = solution.search(nums,target);
    cout<<ans<<endl;
   

    return 0;
    
}
