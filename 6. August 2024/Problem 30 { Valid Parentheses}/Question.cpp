

/*
# 20.  Valid Parentheses
*/
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
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
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        stack<char> st;
        for(auto ch:s){
          if(ch=='(' || ch=='[' || ch=='{') st.push(ch);
          if(ch==')' || ch==']' || ch=='}'){
            if(st.size()==0) return false;
            else if(st.top()=='(' && ch!=')') return false; 
            else if(st.top()=='[' && ch!=']') return false; 
            else if(st.top()=='{' && ch!='}') return false; 
            else st.pop();
          }

        }
    
        if(st.size()==0) return true;
        else return false;
    }   
};


int main(){
   Solution solution; 
 int ans= solution.isValid("()[]{}");

  cout<<ans<<endl;
  return 0;

}
