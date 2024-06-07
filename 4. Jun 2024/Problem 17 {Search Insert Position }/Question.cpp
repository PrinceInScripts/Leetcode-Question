

/*
# 35. Search Insert Position
*/
/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 
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
      
  int searchInsert(vector<int>& nums, int target) {
      int n=nums.size();
      int lo=0;
      int hi=n-1;
      bool flag=false;

      while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(nums[mid]==target){
            flag=true;
            return mid;
        } else if(nums[mid]>target) hi=mid-1;
        else lo=mid+1; 
      }
      
      if(!flag) return lo;
      
    }


   

};

int main()
{
   vector<int> arr={1,3,5,6};  
   int target=7;  

    Solution solution;
    int ans = solution.searchInsert(arr,target);
    
    cout<<ans;
    return 0;
    
}
