

/*
# 523. Continuous Subarray Sum
*/
/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1

*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<regex>
using namespace std;

class Solution {
public:   
     
     
     bool checkSubarraySum1(vector<int>& nums, int k) {
        int n=nums.size();

       for(int i=1;i<n;i++){
        nums[i]+=nums[i-1];
       }
       if(n==2){
         if(nums[1]%k==0) return true;
         else return false;
       } else if(n==3){
          for(int i=1;i<n;i++){
            if((nums[i]+nums[i-1])%k==0) return true;
            else return false;
          }
       }
       int i=1,j=1;
       while(j<n){
          if(nums[j]%k==0) return true;
          else if((nums[j]-nums[i-1])%k==0) return true;
          j++;
          if(j==n-1){
            while(i<n-2){
                if((nums[j]-nums[i-1])%k==0) return true;
                i++;
            }
          }
       }
       return false;

    } 
     bool checkSubarraySum(vector<int>& nums, int k) {
      unordered_map<int,int> map;
      map[0]=-1;
      int sum=0;
      for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(map.find(sum%k)!=map.end()){
           if(i-map[sum%k]>=2) return true;
        } else {
            map[sum%k]=i;
        }
      }
      return false;

    } 
    
   
      
};


int main(){
   vector<int> nums={23,2,4,6,7};
   int k=6;
   Solution solution; 
   int ans= solution.checkSubarraySum(nums,k);

    cout<<ans;
    return 0;
}
