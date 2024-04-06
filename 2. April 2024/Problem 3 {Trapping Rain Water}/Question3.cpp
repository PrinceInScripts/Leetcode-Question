/*
# 42.Trapping Rain Water
*/
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
      int trap(vector<int>& height) {
            int n=height.size();
            int prev[n];
            prev[0]=-1;
            int max=height[0];
            for(int i=1;i<n;i++){
                prev[i]=max;
                if(height[i]>max) max=height[i];
            }

            int next[n];
            next[n-1]=-1;
            max=height[n-1];
            for(int i=n-2;i>=0;i--){
                next[i]=max;
                if(height[i]>max) max=height[i];
            }

            int mini[n];
            for(int i=0;i<n;i++){
                mini[i]=min(prev[i],next[i]);
            }

            int water=0;
            for(int i=1;i<n-1;i++){
                if(height[i]<mini[i]){
                    water+=mini[i]-height[i];
                }
            }
        
        return water;
    }
};


int main(){
    vector<int> nums = {4,2,0,3,2,5};
    
    Solution solution; 
    int water=solution.trap(nums);

    // for (int num : nums) {
    //     cout << num << " ";
    // }
    cout<<water << endl;

    return 0;
}
