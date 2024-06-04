

/*
# 409. Longest Palindrome
*/
/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 
 
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
    int longestPalindrome(string s) {
       unordered_map<char,int> map;

       for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(map.find(ch) != map.end()) map[ch]++;
        else map[ch]=1;        
       }

       int ans=0;
       bool isFirstOdd=false;

       for(auto& el:map){
          if(el.second%2==0){
            ans+=el.second;
          } else{
            ans+=el.second;
            if(!isFirstOdd){
                isFirstOdd=true;
            }else{
                ans-=1;
            }
          }
       }
       
       return ans;


    }

};

int main()
{
   string s = "abccccdd";
 
    

    Solution solution;
   int ans = solution.longestPalindrome(s);
    cout<<ans<<endl;
   

    return 0;
    
}
