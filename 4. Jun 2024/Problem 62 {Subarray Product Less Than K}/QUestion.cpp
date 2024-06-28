

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
   
     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
          int n=nums.size();
          int i=0,j=0,count=0;
          int product=1;
          while(j<n){
            if(product<k) product*=nums[j];
            while(product>=k){
                count+=(j-i);
                product/=nums[i];
                i++;
            }
            j++;
          }
           while(i<n){
                count+=(j-i);
                product/=nums[i];
                i++;
            }

            return count;

         
         
      }
      
     
    
   
};


int main(){
   vector<int> nums={10,5,2,6};
   int k=100;
 
    Solution solution; 
   int ans=solution.numSubarrayProductLessThanK(nums,k);

    
    cout<<ans;

    return 0;
}
