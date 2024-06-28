

/*
# 1493. Longest Subarray of 1's After Deleting One Element
*/
/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

 
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
   
     int longestSubarray(vector<int>& nums) {
          int n=nums.size();
          int maxSubLen=0;
          int zeroPos=-1;
          int i=0,j=0,count=0;

          while(j<n){
            int prevZeroPos=zeroPos;
            if(nums[j]==0){
                count++;
                zeroPos=j;
            } 
            if(count<=1) j++;
            else {
                maxSubLen=max(maxSubLen,j-i);
                count--;
                i=prevZeroPos+1;
                j++;
            }
          }

          maxSubLen=max(maxSubLen,j-i);
          return maxSubLen-1;

         
         
      }
     int longestSubarray1(vector<int>& nums) {
          int n=nums.size();
          int maxSubLen=INT_MIN;
          int len=INT_MIN;
          int i=0,j=0,count=0;

          while(j<n){
            if(nums[j]==1) j++;
            else {
                if(count<1){
                    count++;
                    j++;
                } else {
                    len=j-i;
                    maxSubLen=max(maxSubLen,len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
          }
          len=j-i;
          maxSubLen=max(maxSubLen,len);
          return maxSubLen-1;
         
      }
     
    
   
};


int main(){
   vector<int> nums={0,1,1,1,0,1,1,0,1};
 
    Solution solution; 
   int ans=solution.longestSubarray(nums);

    
    cout<<ans;

    return 0;
}
