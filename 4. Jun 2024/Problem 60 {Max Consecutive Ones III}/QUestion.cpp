

/*
# 1004. Max Consecutive Ones III
*/
/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

 
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
   
      int longestOnes(vector<int>& nums, int k) {
          int n=nums.size();
          int maxLen=INT_MIN,len=INT_MIN;
          int i=0,j=0,flips=0;

          while(j<n){
            if(nums[j]==1) j++;
            else {
               if(flips<k){
                flips++;
                j++;
               } else{
                len=j-i;
                maxLen=max(maxLen,len);
                while(nums[i]==1) i++;
                i++;
                j++;
            }
            }
          }
            len=j-i;
            maxLen=max(maxLen,len);
          return maxLen;

         
         
      }
     
    
   
};


int main(){
   vector<int> nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
   int k=3;
 
    Solution solution; 
   int ans=solution.longestOnes(nums,k);

    
    cout<<ans;

    return 0;
}
