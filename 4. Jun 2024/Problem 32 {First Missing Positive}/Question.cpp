

/*
# 41. First Missing Positive
*/
/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/

#include <iostream>
#include <vector> 
#include<algorithm>
#include <limits.h>
#include<unordered_map>
using namespace std;

class Solution
{
public:
   
 
   int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<=0 || nums[i]==i+1) i++;
            else swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return -1;
}
//    int firstMissingPositive(vector<int>& nums) {
//         int n=nums.size();
        
//         int i=0;
//         while(i<n){
//             if(nums[i]<=0 || nums[i]<n || nums[i]==i+1 || nums[nums[i]-1]==nums[i]) i++;
//             else swap(nums[i],nums[nums[i]-1]);
//         }
//         for(int i=0;i<n;i++){
//            if(nums[i]!=i+1) return i+1;
//         }
//         return -1;
// }


   

};

int main()
{
    vector<int> nums={1,2,0};

    Solution solution;
    int ans = solution.firstMissingPositive(nums);
   
    cout<<ans;
    return 0;
    
}
