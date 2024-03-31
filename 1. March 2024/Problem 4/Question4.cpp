/*
# 75. Sort Colors
*/
/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   void sortColors(vector<int>& nums) {
       int noo=0;
       int no1=0;
       int no2=0;
       int n=nums.size();

       for(int i=0;i<n;i++){
            if(nums[i]==0) noo++;
            else if(nums[i]==1) no1++;
            else no2++;
       }

       for(int i=0;i<n;i++){
         if(i<noo) nums[i]=0;
         else if(i>=noo && i<no1+noo) nums[i]=1;
         else nums[i]=2;
       }
    }
};


int main(){
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution solution; 
    solution.sortColors(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
