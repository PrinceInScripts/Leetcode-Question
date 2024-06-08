

/*
# 287. Find the Duplicate Number
*/
/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 
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
      
  int findDuplicate(vector<int>& nums) {
      int n=nums.size()-1;
      sort(nums.begin(),nums.end());

      for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]){
            return nums[i];
        }
      }
      return -1;
      
    }


   

};

int main()
{
   vector<int> arr={1,3,4,2,2};  
   int target=7;  

    Solution solution;
    int ans = solution.findDuplicate(arr);
    
    cout<<ans;
    return 0;
    
}
