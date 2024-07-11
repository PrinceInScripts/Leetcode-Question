

/*
# 58. Length of Last word
*/
/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<regex>
using namespace std;

class Solution {
public:   
     
      int lengthOfLastWord(string s) {
        stringstream ss(s);
        string temp;
        string ans;
        while(ss>>temp){
            ans=temp;
        }
        return ans.length();

    } 
      
};


int main(){
 string words="Hello World";
   Solution solution; 
   int ans=solution.lengthOfLastWord(words);

    
    cout<<ans;
    return 0;
}
