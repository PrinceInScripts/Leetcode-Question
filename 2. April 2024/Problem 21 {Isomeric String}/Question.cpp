/*
# 205. Isomeric string
*/
/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
      bool isIsomorphic(string s, string t) {
            if(s.length() != t.length()) return false;

            vector<int> v(150,1000);

            for(int i=0;i<s.length();i++){
                int idx=(int)s[i];

                if(v[idx]==1000) v[idx]=s[i]-t[i];
                else if(v[idx]!=(s[i]-t[i])){
                    return false;
                }
            }

            for(int i=0;i<150;i++){
                v[i]=1000;
            }

            for(int i=0;i<t.length();i++){
                int idx=(int)t[i];

                if(v[idx]==1000) v[idx]=t[i]-s[i];
                else if(v[idx]!=(t[i]-s[i])){
                    return false;
                }
            }

            return true;
    }
};


int main(){
    
    string s="paper";
    string t="title";

    Solution solution; 
    bool score=solution.isIsomorphic(s,t);

    
    cout<<score << endl;

    return 0;
}
