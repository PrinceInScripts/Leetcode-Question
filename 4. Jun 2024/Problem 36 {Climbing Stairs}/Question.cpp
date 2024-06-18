

/*
# 70. Climbing stairs
*/
/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
*/

#include <iostream>
#include <vector> 
#include<algorithm>
#include <limits.h>
#include<unordered_map>
using namespace std;

class Solution
{
public:
   
 
  int climbStairs2(int n) {
      if(n==1) return 1;
      if(n==2) return 2;

      return climbStairs(n-1)+climbStairs(n-2);
}
int helper(int n,unordered_map<int,int>& memo){
    if(n<=1) return 1;

    if(memo.find(n) != memo.end()) return memo[n];

    memo[n]=helper(n-1,memo)+helper(n-2,memo);
    return memo[n];
}
  int climbStairs1(int n) {
     unordered_map<int,int> memo;
     return helper(n,memo);
}
  int climbStairs(int n) {
     if(n<=1) return 1;

     int curr=1,prev=1;
     for(int i=2;i<=n;i++){
        int temp=curr;
        curr=curr+prev;
        prev=temp;
     }
     return curr;
}


   

};

int main()
{
    int num=45;

    Solution solution;
    int ans = solution.climbStairs(num);
    int ans1 = solution.climbStairs1(num);
    int ans2 = solution.climbStairs2(num);
   
    // cout<<ans;
    // cout<<ans1;
    cout<<ans2;
    return 0;
    
}
