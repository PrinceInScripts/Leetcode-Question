

/*
# 1446. Consecutive Characters
*/
/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
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
#include<queue>
using namespace std;

class Solution {
public:  
    
   int maxPower(string s) {
             int count=1;
             int mx=INT_MIN;
                              mx=max(mx,count);

             for(int i=1;i<s.size();i++){
                if(s[i]==s[i-1]){
                  count++;
                }else{
                 mx=max(mx,count);
                 count=1;
                }
             }

             return mx;
    }   
};


int main(){
    Solution solution; 
    int ans= solution.maxPower("abbcccddddeeeeedcba");
    
  cout<<ans;
    return 0;

}
