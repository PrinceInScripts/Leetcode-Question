

/*
# 977. Squares of a Sorted Array
*/
/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?


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
      vector<int> sortedSquares1(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=(nums[i]*nums[i]);
        }

        sort(nums.begin(),nums.end());
        
        return nums;

      } 
      vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);

        int i=0,j=n-1,k=n-1;

        while(i<=j){
            if(abs(nums[i])<=abs(nums[j])){
                res[k]=nums[j]*nums[j];
                j--;
                k--;
            }else {
                res[k]=nums[i]*nums[i];
                i++;
                k--;
            }
        }
        return res;

      } 
      
};


int main(){
 vector<int> nums={-4,-1,0,3,10};
   Solution solution; 
   vector<int> ans=solution.sortedSquares(nums);

    
    for(auto el:ans) cout<<el<<" ";
    return 0;
}
