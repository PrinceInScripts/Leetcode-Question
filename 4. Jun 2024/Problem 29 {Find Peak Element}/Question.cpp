

/*
# 162. Find Peak Element
*/
/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
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
   
  int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        
        int lo=0;
        int hi=n-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(n==1) return 0;
            else if(n==2){
                if(nums[0]>nums[1]) return 0;
                else return 1;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
       
}


   

};

int main()
{
    vector<int> nums={2,1};

    Solution solution;
    int ans = solution.findPeakElement(nums);
    
    cout<<ans;
    return 0;
    
}
