/*
# 219. Contain Duplicates II
*/
/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    if((-(i-j))<=k){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main(){

    vector<int> nums = {1,2,3,1,2,3};
    int k=2;

    Solution solution;
    bool score = solution.containsNearbyDuplicate(nums,k);

    cout << score << endl;

    return 0;
}
