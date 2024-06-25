

/*
# 645. Set Mismatch
*/
/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 
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
   
     vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
              while(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return {nums[i],i+1};
            }
        }

        return {-1,-1};
    }
   
};


int main(){
   vector<int> nums={3,2,3,4,6,5};
 
    Solution solution; 
    vector<int> ans=solution.findErrorNums(nums);

    
    for(auto el:ans){
        cout<<el<<" ";
    }

    return 0;
}
