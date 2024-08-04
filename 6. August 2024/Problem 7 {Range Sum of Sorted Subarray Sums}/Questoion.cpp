

/*
# 1508. Range Sum of Sorted Subarray Sums
*/
/*
You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
 

Constraints:

n == nums.length
1 <= nums.length <= 1000
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2
 
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<set>
#include<regex>
#include<string>
using namespace std;

class Solution {
public:   
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       int size=(n*(n+1))/2;
       vector<int> newArr(size);
       int i=0,j=1;
       int sum=nums[i];
       newArr[0]=sum;
       int k=1;
          while(i<n){
            while(j<n){
                sum+=nums[j++];
                newArr[k++]=sum;
            }
            sum=0;
            j=++i;
          }

      sort(newArr.begin(),newArr.end());
      int sumNewArr=0;
      left-=1;
      int mod=1e9+7;
      while(left<right){
         sumNewArr+=newArr[left];
         left++;
      }

      return sumNewArr%mod;

    }
    
    
        
};


int main(){
  vector<int> nums={1,2,3,4};
  int n=4;
  int left=1;
  int right=5;
   Solution solution; 
 int ans= solution.rangeSum(nums,n,left,right);

  cout<<ans<<endl;
  return 0;

}
