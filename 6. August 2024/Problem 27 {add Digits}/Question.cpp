

/*
# 258. Integer To English Words
*/
/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 231 - 1
 

Follow up: Could you do it without any loop/recursion in O(1) runtime?
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
   int addDigits(int num) {
         if(num/10==0) return num;
         string str=to_string(num);
         int n=0;
         for(auto st:str){
             n+=(st-'0');
         }
         return addDigits(n);
    }
    
    
        
};


int main(){
  int num=38;
   Solution solution; 
 int ans= solution.addDigits(num);

  cout<<ans<<endl;
  return 0;

}
