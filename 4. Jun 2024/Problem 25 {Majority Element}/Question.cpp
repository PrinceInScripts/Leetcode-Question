

/*
# 169. Majority Element
*/
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 
 
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
      
  int majorityElement(vector<int>& nums) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      return nums[n/2];
    }


   

};

int main()
{
   vector<int> arr={2,2,1,1,1,2,2};   

    Solution solution;
    int ans = solution.majorityElement(arr);
    
    cout<<ans;
    return 0;
    
}
