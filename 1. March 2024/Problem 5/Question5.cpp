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
   void swap(int* a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}
   void sortColors(vector<int>& nums) {
       int n=nums.size();
       int lo=0;
       int mid=0;
       int hi=n-1;

      while(mid<=hi){
           if(nums[mid]==2){
              swap(&nums[mid],&nums[hi]);
              hi--;
           }

           else if(nums[mid]==0){
            swap(&nums[lo],&nums[mid]);
             mid++;
             lo++;
           }

           else mid++;
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
