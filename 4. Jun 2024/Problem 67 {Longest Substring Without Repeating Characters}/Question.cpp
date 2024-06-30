

/*
# 3. Longest Substring Without Repeating Characters
*/
/*

Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
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
   
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int> freq;
        int i=0,j=0,maxLen=INT_MIN;
        while(j<s.size()){
            if(freq[s[j]]==1){
               maxLen=max(maxLen,j-i);
               i=j;
               j++;
            } else {
                freq[s[j]]=1;
                j++;
            }
        }

        return maxLen;
    }
    
    
    
   
};


int main(){
     string s="abcabcbb";
 
    Solution solution; 
    int ans=solution.lengthOfLongestSubstring(s);

    
    cout<<ans;

    return 0;
}
