/*
# 217. Contain Duplicates
*/
/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int> &nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        bool flag=false;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                flag= true;
                break;
            }
        }

        return flag;
    }
};

int main(){

    vector<int> nums = {1,2,3,4};

    Solution solution;
    bool score = solution.containsDuplicate(nums);

    cout << score << endl;

    return 0;
}
