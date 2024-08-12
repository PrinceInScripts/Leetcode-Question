

/*
# 84. Largest Rectangle in Histogram
*/
/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
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
     int largestRectangleArea(vector<int>& heights) {
           int maxArea=INT_MIN;
           int n=heights.size();

           for(int i=0;i<n;i++){
              int width=0;
              int k=i;
              for(int j=k;j>=0;j--){
                if(heights[j]>=heights[i]) width++;
                else break;
              }
              for(int j=i+1;j<n;j++){
                if(heights[j]>=heights[i]) width++;
                else break;;
              }
              maxArea=max(maxArea,(heights[i]*width));
           }
           return maxArea;
    }

        
     
};


int main(){
    vector<int> heights={2,1,5,6,2,3};
    Solution solution; 
    int ans= solution.largestRectangleArea(heights);
    
    cout<<ans;
    return 0;

}
