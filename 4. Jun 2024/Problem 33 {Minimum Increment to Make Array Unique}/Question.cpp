

/*
# 945. Minimum Increment to Make Array Unique
*/
/*
You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].
Example 2:

Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
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
   
 
   int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=1;i<n;i++){
           if(nums[i]<=nums[i-1]){
            int num=nums[i-1]-nums[i];
            count+=num+1;
            nums[i]=nums[i-1]+1;
           }

        }
        return count;
        
        
}


   

};

int main()
{
    vector<int> nums={2,2,2,2,0};

    Solution solution;
    int ans = solution.minIncrementForUnique(nums);
   
    cout<<ans;
    return 0;
    
}
