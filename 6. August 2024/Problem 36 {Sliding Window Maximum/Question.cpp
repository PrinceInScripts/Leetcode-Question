

/*
# 239.Sliding Widnow Maximum
*/
/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:  
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
          vector<int> ans;
          int n=nums.size();
          for(int i=0;i<n-k+1;i++){
             int mx=INT_MIN;
             for(int j=i;j<i+k;j++){
                 mx=max(mx,nums[j]);
             }
             ans.push_back(mx);
          }
          return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          vector<int> ans;
          int n=nums.size();
          vector<int> ngi(n);
          stack<int> st;
          ngi[n-1]=n;
          st.push(n-1);
          for(int i=n-2;i>=0;i--){
              while(st.size()>0 && nums[st.top()]<=nums[i]) st.pop();
              if(st.size()==0) ngi[i]=n;
              else ngi[i]=st.top();
              st.push(i);
          }
          int j=0;
         for(int i=0;i<n-k+1;i++){
            int mx=nums[j];
            while(ngi[j]<i+k){
                mx=nums[ngi[j]];
                if(ngi[j]>=i+k) break;
                j=ngi[j];
            }
            ans.push_back(mx);
         }
         return ans;
    }

        
     
};


int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    Solution solution; 
    vector<int> ans= solution.maxSlidingWindow(nums,3);
    
    for(auto el:ans){
        cout<<el<<" ";
    }
    return 0;

}
