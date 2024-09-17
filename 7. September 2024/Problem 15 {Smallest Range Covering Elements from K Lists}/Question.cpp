

/*
# 632.  Smallest Range Covering Elements from K Lists
*/
/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include <limits.h>
#include<cmath>
using namespace std;

class Solution
{
public:
    typedef pair<int,pair<int,int>> pip;
     vector<int> smallestRange(vector<vector<int>>& nums) {
            priority_queue<pip,vector<pip>,greater<pip>> pq;
            int mx=INT_MIN;
            int start=-1;
            int end=-1;
            
            int minRange=INT_MAX;
            for(int i=0;i<nums.size();i++){
                  mx=max(mx,nums[i][0]);
                  pq.push({nums[i][0],{i,0}});
            }           
            while(1){
                    pip t=pq.top();
                    pq.pop();
                   
                    int currentMin=t.first;
                    int startIdx=t.second.first;
                    int endIdx=t.second.second;
        
                    if((mx-currentMin)<minRange){
                        minRange=mx-currentMin;
                        start=currentMin;
                        end=mx;
                    }

                    if(nums[startIdx].size()==endIdx+1) break;

                    int nxtEl=nums[startIdx][endIdx+1];
                    pq.push({nxtEl,{startIdx,endIdx+1}});
                    mx=max(mx,nxtEl);
           }
           return {start,end};
    }
     vector<int> smallestRange1(vector<vector<int>>& nums) {
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
            int mx=INT_MIN;
            int start=-1;
            int end=-1;
            
            int minRange=INT_MAX;
            for(int i=0;i<nums.size();i++){
                  mx=max(mx,nums[i][0]);
                  pq.push({nums[i][0],i,0});
            }           
            while(1){
                    vector<int> t=pq.top();
                    pq.pop();
                   
                    int currentMin=t[0];
                    int startIdx=t[1];
                    int endIdx=t[2];
        
                    if((mx-currentMin)<minRange){
                        minRange=mx-currentMin;
                        start=currentMin;
                        end=mx;
                    }

                    if(nums[startIdx].size()==endIdx+1) break;

                    int nxtEl=nums[startIdx][endIdx+1];
                    pq.push({nxtEl,startIdx,endIdx+1});
                    mx=max(mx,nxtEl);
           }
           return {start,end};
    }
   

};

int main()
{
   vector<vector<int>> nums={{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
  
    

    Solution solution;
   vector<int> ans = solution.smallestRange(nums);

  for(auto el:ans){
    cout<<el<<" ";
  }
    return 0;
    
}
