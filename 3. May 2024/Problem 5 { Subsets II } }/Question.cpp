/*
# 90.Subsets II
*/
/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void helper(vector<int> &nums,vector<int> ans,vector<vector<int>>& result,int idx,bool flag){
              if(idx==nums.size()){
                result.push_back(ans);
                return;
              }

              if(idx==nums.size()-1){
                helper(nums,ans,result,idx+1,true);
                if(flag){
                   ans.push_back(nums[idx]);
                   helper(nums,ans,result,idx+1,true);
                }
                return;
              }
              
              if(nums[idx]==nums[idx+1]){
                helper(nums,ans,result,idx+1,false);
                if(flag){
                   ans.push_back(nums[idx]);
                   helper(nums,ans,result,idx+1,true);
                }
              } else {
                helper(nums,ans,result,idx+1,true);
                if(flag){
                   ans.push_back(nums[idx]);
                   helper(nums,ans,result,idx+1,true);
                }
              }
    }
     
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
              vector<vector<int>> result;
              vector<int> ans;
              sort(nums.begin(),nums.end());
              helper(nums,ans,result,0,true);
              return result;
    }
};



int main(){
    vector<int> nums = {1,2,1};
    
    Solution solution; 
    vector<vector<int>> result = solution.subsetsWithDup(nums);

    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
