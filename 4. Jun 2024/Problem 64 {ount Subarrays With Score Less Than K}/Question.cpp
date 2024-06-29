

/*
# 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
*/
/*

Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

 

Example 1:

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
Example 2:

Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
 

Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 104
1 <= k <= arr.length
0 <= threshold <= 104
 
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
