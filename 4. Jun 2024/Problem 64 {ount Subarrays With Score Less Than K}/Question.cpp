

/*
# 2302.  Count Subarrays With Score Less Than K
*/
/*

The score of an array is defined as the product of its sum and its length.

For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
Example 2:

Input: nums = [1,1,1], k = 5
Output: 5
Explanation:
Every subarray except [1,1,1] has a score less than 5.
[1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
Thus, there are 5 subarrays having scores less than 5.
 
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
   
    long long countSubarrays(vector<int>& nums, long long k) {
         int n=nums.size();
         long long count=0,i=0,j=0,sum=0;

         for(j=0;j<n;j++){
            sum+=nums[j];

            while(sum*(j-i+1)>=k){
                sum-=nums[i];
                i++;
            }
            count+=(j-i+1);
         }
         return count;
    }
    long long countSubarrays1(vector<int>& nums, long long k) {
         int n=nums.size();
         long long count=0;
         for(int i=0;i<n;i++){
            if(nums[i]<k) count++;
         }
        
         int t=2;
         while(t<=n){
            long long sum=0;
            bool flag=false;
            for(int i=0;i<t;i++){
                sum+=nums[i];
            }
            if(sum*t<k) count++;
            int i=1;
            int j=t;
            while(j<n){
                sum=sum+nums[j]-nums[i-1];
                if(sum*t<k){
                    count++;
                    flag=true;
                } 
                i++;
                j++;
            }
            if(!flag) return count;
            t++; 
         }
         return count;
    }
    
    
    
   
};


int main(){
//    vector<int> nums={1,2,9,1,5};
   vector<int> nums={2,1,4,3,5};
   int k=10;
 
    Solution solution; 
    long long ans=solution.countSubarrays(nums,k);

    
    cout<<ans;

    return 0;
}
