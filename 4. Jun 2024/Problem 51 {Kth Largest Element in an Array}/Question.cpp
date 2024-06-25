

/*
# 215. Kth Largest Element in an Array
*/
/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 
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
    int partition(vector<int>& nums,int si,int ei,int k){
        int pivotElement=nums[ei];
        int i=si;

        for(int j=si;j<ei;j++){
            if(nums[j]>=pivotElement){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[ei]);
        return i;
        
    }
    int helper(vector<int>& nums,int si,int ei, int k){
        if(si<=ei){
        int pivotIdx=partition(nums,si,ei,k);

        if(pivotIdx+1==k) return nums[pivotIdx];
        else if(pivotIdx+1<k) return helper(nums,pivotIdx+1,ei,k);
        else return helper(nums,si,pivotIdx-1,k);
        }
        return -1;
        
    }
    int findKthLargest(vector<int>& nums, int k) {
       return helper(nums,0,nums.size()-1,k);
    }
   
};


int main(){
   vector<int> nums={3,2,1,5,6,4};
   int k=2;
 
    Solution solution; 
    int ans=solution.findKthLargest(nums,k);

    
    cout<<ans;

    return 0;
}
