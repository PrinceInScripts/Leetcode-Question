

/*
# 349.Intersection of Two Arrays I
*/
/*
Given two integer arrays nums1 and nums2, return an array of their 
intersection
. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
       unordered_set<int> set;
       vector<int> ans;
       if(n1<n2){
         for(int i=0;i<n1;i++){
            int left=0;
            int right=n2-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums2[mid]==nums1[i]){
                    set.insert(nums1[i]);
                    nums1[mid]=-1;
                    left=mid+1;
                } else if(nums2[mid]>nums1[i]) right=mid-1;
                else left=mid+1;
            }
         }
       } else {
           for(int i=0;i<n2;i++){
            int left=0;
            int right=n1-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums1[mid]==nums2[i]){
                    set.insert(nums2[i]);
                    nums1[mid]=-1;
                    left=mid+1;
                } else if(nums1[mid]>nums2[i]) right=mid-1;
                else left=mid+1;
            }
         }
       }

        for(auto& num:set){
           ans.push_back(num);
         }

         return ans;
       
    }
};


int main(){
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};
   
    
    Solution solution; 
    vector<int> ans=solution.intersection(nums1,nums2);

    
    for(auto el:ans){
        cout<<el<<" ";
    }
    return 0;
}
