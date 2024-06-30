

/*
# 643. Maximum Average Subarray I
*/
/*

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
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
   
    double findMaxAverage(vector<int>& nums, int k) {
         int n=nums.size();
         double sum=0;

         for(int i=0;i<k;i++){
            sum+=nums[i];
         }
         
         double avg=(double)sum/(double)k;

         double maxAvg=avg;

         int i=1;
         int j=k;
         while(j<n){
            sum=sum+nums[j]-nums[i-1];
            avg=(double)sum/(double)k;
            maxAvg=max(maxAvg,avg);
            i++;
            j++;
         }

         return maxAvg;
    }
    
    
    
   
};


int main(){
     vector<int> nums={1,12,-5,-6,50,3};
     int k=4;
 
    Solution solution; 
    double ans=solution.findMaxAverage(nums,k);

    
    cout<<ans;

    return 0;
}
