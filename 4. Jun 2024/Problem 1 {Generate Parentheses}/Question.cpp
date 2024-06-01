

/*
# 22. Generate Parentheses
*/
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public: 
   void helper(string str,vector<string>& ans,int open,int close,int n){
      if(close==n){
        ans.push_back(str);
        return;
      }
      if(open<n) helper(str+'(',ans,open+1,close,n);
      if(close<open) helper(str+')',ans,open,close+1,n);
   }
     
    vector<string> generateParenthesis(int n) {
      vector<string> ans;
      helper("",ans,0,0,n);
      return ans;       
    }
   

};

int main()
{
    int num=3;

    Solution solution;
    vector<string> ans = solution.generateParenthesis(num);

    for(auto num:ans){
        cout<<num<<" ";
    }

    return 0;
}
