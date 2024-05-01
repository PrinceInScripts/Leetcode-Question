/*
# 128. Longest Consecutive Sequence
*/
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
     int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int> ans;
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            
            if(nums[i]-1 != nums[i-1]) {
                ans.push_back(nums[i-1]);
                break;
                }
            else ans.push_back(nums[i-1]);
        }

      

        return ans.size(); 
    }
};

int main(){

    vector<int> nums = {100,4,200,1,3,2};

    Solution solution;
    int number = solution.longestConsecutive(nums);

    cout << number << endl;

    return 0;
}
