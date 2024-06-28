

/*
# 209. Minimum Size Subarray Sum
*/
/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

 
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:   
   
      int minSubArrayLen(int target, vector<int>& nums) {
          int n=nums.size();
          int minLen=INT_MAX;
          bool flag=false;

          for(int i=0;i<n;i++){
             int len=INT_MAX;
             
             int sum=0;
             for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum>=target){
                    flag=true;
                    len=j-i+1;
                    break;
                } 
             }
            minLen=min(minLen,len);
            
          }
          if(!flag) return 0;
          return minLen;
         
      }
    
   
};


int main(){
//    vector<int> nums={2,3,1,2,4,3};
//    int target=7;
   vector<int> nums={1,1,1,1,1,1,1,1};
   int target=11;
 
    Solution solution; 
   int ans=solution.minSubArrayLen(target,nums);

    
    cout<<ans;

    return 0;
}
