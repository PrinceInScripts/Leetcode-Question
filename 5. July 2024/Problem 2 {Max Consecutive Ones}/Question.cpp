

/*
# 485.Max Consecutive Ones
*/
/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

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
   
   int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,maxLen=INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else {
                maxLen=max(maxLen,j-i);
                i=j+1;
                j++;
            }
        }
        maxLen=max(maxLen,j-i);
        return maxLen;
    }
    
    
    
   
};


int main(){
    vector<int> arr={1,1,0,1,1,1};
    
    Solution solution; 
    int ans=solution.findMaxConsecutiveOnes(arr);

    
    cout<<ans;

    return 0;
}
