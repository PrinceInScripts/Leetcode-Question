

/*
# 560. Subarray Sum Equals K
*/
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107


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
      int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        int i=0,j=1,count=0;
        int sum=nums[0];
        while(j<n){
            if(sum==k) count++;
            if(i==0) sum=nums[j];
            else {
                sum=nums[j]-nums[i-1];
            }
            j++;
        }

      } 
      
};


int main(){
   vector<int> nums={1,2,3};
   int k=3;
   Solution solution; 
   int ans=solution.subarraySum(nums,k);

    
    cout<<ans;

    return 0;
}
