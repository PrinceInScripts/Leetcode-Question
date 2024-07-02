

/*
# 350.Intersection of Two Arrays II
*/
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
       vector<int> ans;
       int i=0,j=0;
        
       while(i<n1 && j<n2){
        if(nums1[i]==nums2[j]){
           ans.push_back(nums1[i]);
           i++;
           j++;
        } else if(nums1[i]<nums2[j]){
            i++;
        } else {
            j++;
        }

        return ans;
       
       
       }
       
    }
};


int main(){
    vector<int> nums1={21,47,80,4,3,24,87,12,22,11,48,6,89,80,74,71,74,55,58,56,4,98,40,66,49,53,62,27,3,66,78,24,48,69,88,12,80,63,98,65,46,35,72,5,64,72,7,29,37,3,2,75,44,93,79,78,13,39,85,26,15,41,87,47,29,93,41,74,6,48,17,89,27,61,2,68,99,57,45,73,25,33,38,32,58};
    vector<int> nums2={1,39,6,81,85,10,38,22,0,89,57,93,58,69,65,80,84,24,27,54,37,36,26,88,2,7,24,36,51,5,74,57,45,56,55,67,25,33,78,49,16,79,74,80,36,27,89,49,64,73,96,60,92,31,98,72,22,31,0,93,70,87,80,66,75,69,81,52,94,90,51,90,74,36,58,38,50,9,64,55,4,21,49,60,65,47,67,8,38,83};
    vector<int> nums3={21,47,80,4,24,87,22,6,89,80,74,74,55,58,56,98,66,49,27,78,24,69,88,80,65,72,5,64,7,37,2,75,93,79,39,85,26,93,74,89,27,57,45,73,25,33,38,58};
    
    Solution solution; 
    vector<int> ans=solution.intersect(nums1,nums2);

    
    for(auto el:ans){
        cout<<el<<" ";
    }
    cout<<endl;
    cout<<endl;
    sort(nums3.begin(),nums3.end());
    for(auto el:nums3){
        cout<<el<<" ";
    }


    
    return 0;
}
