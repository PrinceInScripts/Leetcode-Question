

/*
# 912. Sort the Array
*/
/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
 
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
     void mergeSort(vector<int>& a,vector<int>& b,vector<int>& arr){
        int i=0,j=0,k=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]) arr[k++]=a[i++];
            else arr[k++]=b[j++];
        }
        if(i==a.size()){
            while(j<b.size()) arr[k++]=b[j++];
        }
        if(j==b.size()){
            while(i<a.size()) arr[k++]=a[i++];
        }

     }      
     void sorted(vector<int>& nums){
       
           int n=nums.size()/2;
           int m=nums.size()-n;
           if(nums.size()==1) return ;
           vector<int> a(n);
           vector<int> b(m);

           for(int i=0;i<n;i++){
               a[i]=nums[i];
           }
           for(int i=0;i<m;i++){
               b[i]=nums[i+n];
           }

           sorted(a);
           sorted(b);

           mergeSort(a,b,nums);
           a.clear();
           b.clear();
     }
     vector<int> sortArray(vector<int>& nums) {
         sorted(nums);
         return nums;

      }
        
};


int main(){
  vector<int> nums={5,1,1,2,0,0};
   Solution solution; 
  vector<int> ans= solution.sortArray(nums);

  for(auto el:ans){
    cout<<el<<" ";
  }
  return 0;

}
