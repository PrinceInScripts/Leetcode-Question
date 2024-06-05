

/*
# 704. Binary Search
*/
/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 
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
       int lo=0;
       int hi=nums.size()-1;

       while(lo<=hi){
        int mid=(lo+hi)/2;

        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) lo=mid+1;
        else if(nums[mid]>target) hi=mid-1;
       }
       return -1;
    }
   

};

int main()
{
    vector<int> nums={-1,0,3,5,9,12};
    int target=-1;

    Solution solution;
    int ans = solution.search(nums,target);
    cout<<ans;

    return 0;
    
}
