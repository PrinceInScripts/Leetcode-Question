

/*
# 448. Find All Numbers Disappeared in an Array
*/
/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
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
   
 
   vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int i=0;
        while(i<n){
            int correctIdx=nums[i]-1;
            if(nums[i]==nums[correctIdx]) i++;
            else swap(nums[i],nums[correctIdx]);
        }
        for(int i=0;i<n;i++){
            if(i!=nums[i]-1){
              ans.push_back(i+1);
            }
        }
        return ans;
}


   

};

int main()
{
    vector<int> nums={4,3,2,7,8,2,3,1};

    Solution solution;
    vector<int> ans = solution.findDisappearedNumbers(nums);
   
    for(int el:ans){
        cout<<el<<" ";
    }
    return 0;
    
}
