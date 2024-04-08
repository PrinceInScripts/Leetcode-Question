

/*
# 4. Median of Two Sorted Array
*/
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
     void display(vector<int> v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
     }
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           int m=nums1.size();
           int n=nums2.size();
           double median;
         
           for(int i=0;i<n;i++){
            nums1.push_back(nums2[i]);
           }
          
           int p=nums1.size();
           sort(nums1.begin(),nums1.end());
           
           if(p%2 != 0){
             int mid=p/2;
             median=(double)nums1[mid];
           } else {
             int mid=p/2;
             double ans=((double)nums1[mid-1]+(double)nums1[mid])/2;
             median=ans;
           }
           return median;
        
    }
};


int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    
    Solution solution; 
    double median=solution.findMedianSortedArrays(nums1,nums2);

    
    cout<<median << endl;

    return 0;
}
