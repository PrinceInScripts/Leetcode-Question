/*
# 242. Valid Anagram
*/
/*
iven two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/


#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
     bool isAnagram(string s, string t) {
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());

            if(s==t) return true;
            else return false;
    }
};


int main(){
    
    string s="anagram";
    string t="nagaram";

    Solution solution; 
    bool score=solution.isAnagram(s,t);

    
    cout<<score << endl;

    return 0;
}
