

/*
# 260.Single Number III
*/
/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
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
    vector<int> singleNumber(vector<int>& nums) {
       int n=nums.size();
       int res=nums[0];
       int ans1=0,ans2=0;
       for(int i=1;i<n;i++){
          res=res^nums[i];
       }
       int k=0;
       int temp=res;
       while(true){
            if((temp&1)==1){
                break;
            }
            temp=temp>>1;
            k++;
       }
       for(int num:nums){
           if((num>>k)&1==1) ans1^=num;
       }
       ans2=res^ans1;
       return {ans1,ans2};
    }
};


int main(){
    vector<int> arr={1,2,1,3,2,5};
   
    
    Solution solution; 
    vector<int> ans=solution.singleNumber(arr);

    
    for(auto el:ans){
        cout<<el<<" ";
    }
    return 0;
}
