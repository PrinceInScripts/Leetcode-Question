

/*
# 1440.Make Two Arrays Equal by Reversing Subarrays
*/
/*
You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.

 

Example 1:

Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
2- Reverse subarray [4,2], arr becomes [1,2,4,3]
3- Reverse subarray [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
Example 2:

Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
Example 3:

Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr does not have value 9 and it can never be converted to target.
 

Constraints:

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000

 
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<set>
#include<regex>
#include<string>
using namespace std;

class Solution {
public:   
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       vector<int> nums1(1001);
       vector<int> nums2(1001);

       for(int i=0;i<target.size();i++){
           ++nums1[target[i]];
       }
       for(int i=0;i<arr.size();i++){
           ++nums2[arr[i]];
       }

       return nums1==nums2;
    }
    
    
        
};


int main(){
  vector<int> target={1,2,3,4};
  vector<int> arr={2,3,4,1};
   Solution solution; 
 int ans= solution.canBeEqual(target,arr);

  cout<<ans<<endl;
  return 0;

}
