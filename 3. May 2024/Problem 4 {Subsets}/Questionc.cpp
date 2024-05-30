/*
# 78.Subsets
*/
/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void helper(vector<int> &nums,vector<int> ans,vector<vector<int>>& result,int idx){
              if(idx==nums.size()){
                result.push_back(ans);
                return;
              }
              helper(nums,ans,result,idx+1);
              ans.push_back(nums[idx]);
              helper(nums,ans,result,idx+1);
    }
     
     vector<vector<int>> subsets(vector<int>& nums) {
              vector<vector<int>> result;
              vector<int> ans;
              helper(nums,ans,result,0);
              return result;
    }
};



int main(){
    vector<int> nums = {1,2,3};
    
    Solution solution; 
    vector<vector<int>> result = solution.subsets(nums);

    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
