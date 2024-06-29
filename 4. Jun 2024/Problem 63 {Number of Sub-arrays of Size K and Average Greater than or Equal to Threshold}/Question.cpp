

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
   
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
         int n=arr.size();
         int sum=0,count=0;

         for(int i=0;i<k;i++){
            sum+=arr[i];
         }
         if(sum/k>=threshold) count++;
         
         int i=1;
         int j=k;
         while(j<n){
            sum=sum+arr[j]-arr[i-1];
            if(sum/k>=threshold) count++;
            i++;
            j++;
         }

         return count;
    }
    
    
    
   
};


int main(){
   vector<int> nums={11,13,17,23,29,31,7,5,2,3};
   int k=3;
   int threshold=5;
 
    Solution solution; 
    int ans=solution.numOfSubarrays(nums,k,threshold);

    
    cout<<ans;

    return 0;
}
