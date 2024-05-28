

/*
# 247. Contain Duplicates
*/
/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution
{
public:
    // 1 Way Brute force
    /*
    bool containsDuplicate(vector<int>& nums) {
          for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    return true;
                }
            }
            return false;
          }
        
    }
    */

    // 2 way Two Pointer
    /*
       bool containsDuplicate(vector<int>& nums) {
          sort(nums.begin(),nums.end());
          for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return true;
            }
          }
          return false;
          }
        
    */

   //3 way two-pass has table
   /*
     bool containsDuplicate(vector<int>& nums) {
         unordered_map<int,int> seen;

         for(auto num:nums){
            if(seen[num]>=1) return true;
            else seen[num]++;
         }

         return false;
        
    }
    */

  //4 hash-set
   bool containsDuplicate(vector<int>& nums) {
         unordered_set<int> seen;

         for(auto num:nums){
            if(seen.find(num) != seen.end()) return true;
            else seen.insert(num);
         }

         return false;
        
    }
    

    


};

int main()
{
    vector<int> nums = {1,2,3,1};

    Solution solution;
    bool ans = solution.containsDuplicate(nums);

    cout<<ans;

    return 0;
}
