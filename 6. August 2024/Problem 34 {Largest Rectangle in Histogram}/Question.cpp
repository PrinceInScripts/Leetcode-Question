

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
           int n=heights.size();
           vector<int> psi(n);
           vector<int> nsi(n);
           
           //Next Smallest Element
           stack<int> st1;
           nsi[n-1]=n;
           st1.push(n-1);
           for(int i=n-2;i>=0;i--){
              while(st1.size()>0 && heights[st1.top()]>=heights[i]) st1.pop();
              if(st1.size()==0) nsi[i]=n;
              else nsi[i]=st1.top();
              st1.push(i);
           }

           //Previous Smallest Element
           stack<int> st2;
           psi[0]=-1;
           st2.push(0);
           for(int i=1;i<n;i++){
             while(st2.size()>0 && heights[st2.top()]>=heights[i]) st2.pop();
             if(st2.size()==0) psi[i]=-1;
             else psi[i]=st2.top();
             st2.push(i);
           }
           int maxArea=INT_MIN;
           for(int i=0;i<n;i++){
              int width=(nsi[i]-psi[i])-1;
              int area=heights[i]*width;
              maxArea=max(maxArea,area);
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
