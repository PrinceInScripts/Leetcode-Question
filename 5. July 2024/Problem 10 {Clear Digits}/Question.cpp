

/*
# 3175. Clear Digits
*/
/*
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

 

Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".

 

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.

 
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:   
   
     string clearDigits(string s) {
          int idx=-1;
         for(int i=0;i<s.size();i++){
            if(s[i]>=48 && s[i]<=57){
                idx=i;
                break;
            }
         }
         if(idx==-1) return s;
         else {
            string left=s.substr(0,idx-1);
            string right=s.substr(idx+1,s.size()-1);
             return clearDigits(left+right);
         }
        return "";
      }
      
     
    
   
};


int main(){
  string s="c8f";
 
    Solution solution; 
   string ans=solution.clearDigits(s);

    
    cout<<ans;

    return 0;
}
