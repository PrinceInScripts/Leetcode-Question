

/*
# 493. Reverse Pair
*/
/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 
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
    void merge(vector<int>& a,vector<int>& b,vector<int>& v){
        int i=0,j=0,k=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]) v[k++]=a[i++];
            else v[k++]=b[j++];
        }

        while(j<b.size()) v[k++]=b[j++];

        while(i<a.size()) v[k++]=a[i++];
             
    }
    int countPair(vector<int>& a,vector<int>& b){
         int i=0,j=0;
         int count=0;
         while(i<a.size() && j<b.size()){
            if(a[i]>(long long)2*b[j]){
                count+=(a.size()-i);
              
                j++;
            }else {
                i++;
            }
         }

         return count;

    }
    int reversePairs(vector<int>& nums) {
       int n=nums.size();
       int n1=n/2,n2=n-n/2;
       if(n<=1) return 0;
       vector<int> a(n1),b(n2);

       for(int i=0;i<n1;i++){
          a[i]=nums[i];
       }
       for(int i=0;i<n2;i++){
          b[i]=nums[i+n1];
       }
       
       int count= reversePairs(a) + reversePairs(b);
      
       count+=countPair(a,b);

       merge(a,b,nums);

       return count;
    }
   
};


int main(){
   vector<int> nums={1,3,2,3,1};
 
    Solution solution; 
    int ans=solution.reversePairs(nums);

    
    cout<<ans;

    return 0;
}
