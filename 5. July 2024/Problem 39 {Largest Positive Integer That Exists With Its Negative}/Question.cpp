

/*
# 2441.Largest Positive Integer That Exists With Its Negative
*/
/*
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

 

Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.
 

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
     int findMaxK1(vector<int>& nums) {
       unordered_map<int,int> map;
       for(int i=0;i<nums.size();i++){
            int num=abs(nums[i]);
            map[num]++;
       }

       int maxK=-1;

       for(auto& el:map){
         if(el.second==2){
            maxK=max(maxK,el.first);
         }
       }
       return maxK;
    }    
     int findMaxK(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int i=0;
       int j=nums.size()-1;
       int maxK=-1;
       while(nums[i]<0 && nums[j]>0){
             if(abs(nums[i])==nums[j]){
                maxK=nums[j];
                break;
             } else if(abs(nums[i])<nums[j]) j--;
             else if(abs(nums[i])>nums[j]) i++;
             
       }
       return maxK;
    }    
};


int main(){
   vector<int> nums={-1,10,6,7,-7,1};
   Solution solution; 
   int ans= solution.findMaxK(nums);

    cout<<ans;
    return 0;
}
