

/*
# 303. Range Sum Query - Immutable
*/
/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 104 calls will be made to sumRange.
 
 
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class NumArray {
public: 
    vector<int> prefix_sum;
    NumArray(vector<int>& nums) {
        prefix_sum.resize(nums.size());
        prefix_sum[0]=nums[0];
        for(int i=1;i<prefix_sum.size();i++){
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return prefix_sum[right];
        }
        return prefix_sum[right]-(prefix_sum[left-1]);
    }
};

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    
    cout << numArray.sumRange(0, 2) << endl; // Output: 1
    cout << numArray.sumRange(2, 5) << endl; // Output: -1
    cout << numArray.sumRange(0, 5) << endl; // Output: -3

    return 0;
}
