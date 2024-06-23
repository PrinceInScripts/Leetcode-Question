

/*
# 2389. Longest Subsequence With Limited Sum
*/
/*
You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
Example 2:

Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
     
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
         int n=nums.size();
         int m=queries.size();
         vector<int> ans(m);
         sort(nums.begin(),nums.end());

         for(int i=1;i<n;i++){
            nums[i]=nums[i-1]+nums[i];
         }
        
        for(int i=0;i<m;i++){
            int maxlen=0;
            int lo=0;
            int hi=n-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;

                if(nums[mid]>queries[i]){
                   hi=mid-1;
                }
                else{
                    maxlen=mid+1;
                    lo=mid+1;
                }
            }
            ans[i]=maxlen;
        }
       
       
         return ans;
    }
    vector<int> answerQueries1(vector<int>& nums, vector<int>& queries) {
         int n=nums.size();
         int m=queries.size();
         vector<int> ans(m);
         sort(nums.begin(),nums.end());

         for(int i=1;i<n;i++){
            nums[i]=nums[i-1]+nums[i];
         }
        
        for(int i=0;i<m;i++){
            int len=0;
            for(int j=0;j<n;j++){
                if(nums[j]<=queries[i]) len++;
                else break;
            }
            ans[i]=len;
        }
       
       
         return ans;
    }
};


int main(){
   vector<int> nums={4,5,2,1};
   vector<int> queries={3,10,21};
    
    Solution solution; 
    vector<int> ans=solution.answerQueries(nums,queries);

    
    for(int el:ans){
        cout<<el<<" ";
    }

    return 0;
}
