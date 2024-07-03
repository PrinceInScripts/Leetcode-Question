

/*
# 125. Valid Palindrome
*/
/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
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
           
       string extractString(string str){
          regex pattern("[^a-zA-Z0-9]");
          string output= regex_replace(str,pattern,"");
          transform(output.begin(), output.end(), output.begin(), ::tolower);
    return output;

       }
       bool isPalindrome1(string s) {
        int n=s.size();
        stringstream str(s);
        string temp;
        string strs="";
        while(str>>temp){
           strs+=extractString(temp);
        }
        int i=0,j=strs.size()-1;
        while(i<=j){
            if(strs[i]!=strs[j]) return false;
            i++;
            j--;
        }
        return true;
        
    }
       bool isPalindrome(string s) {
        string str="";
        for(auto c:s){
            if(isalnum(c)){
                str+=tolower(c);
            }
        }
        int i=0,j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
        
    }

      
     
    
   
};


int main(){
  string s="A man, a plan, a canal: Panama$";
 
    Solution solution; 
   bool ans=solution.isPalindrome(s);

    
    cout<<ans;

    return 0;
}
