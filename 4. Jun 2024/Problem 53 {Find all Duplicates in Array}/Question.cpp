

/*
# 442. Find All Duplicates in Array
*/
/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 
 
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
   
     vector<int> findDuplicates2(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
              while(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }

        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
               ans.push_back(nums[i]);
            }
        }
       
        return ans;
    }
     vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            int idx=abs(nums[i])-1;
            if(nums[idx]<0) ans.push_back(abs(nums[i]));
            else nums[idx]=-nums[idx];
        }
        return ans;
    }
     vector<int> findDuplicates1(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int> freq;
       vector<int> ans;

       for(int i=0;i<n;i++){
          freq[nums[i]]++;
       }

       for(auto& el:freq){
        if(el.second==2){
           ans.push_back(el.first);
        }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
   
};


int main(){
   vector<int> nums={4,3,2,7,8,2,3,1};
 
    Solution solution; 
    vector<int> ans=solution.findDuplicates(nums);

    
    for(auto el:ans){
        cout<<el<<" ";
    }

    return 0;
}
