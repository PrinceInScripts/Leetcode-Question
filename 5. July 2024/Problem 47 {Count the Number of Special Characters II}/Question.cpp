

/*
# 3121. Count the Number of Special Characters II
*/
/*
You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

There are no special characters in word.

Example 3:

Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in word.

 

Constraints:

1 <= word.length <= 2 * 105
word consists of only lowercase and uppercase English letters.
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
     int numberOfSpecialChars1(string word) {
        unordered_map<char,int> lower;
        unordered_map<char,int> upper;

        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                if(lower.find(word[i])==lower.end()){
                    lower[word[i]]=i;
                }
            } else {
                if(upper.find(word[i])==upper.end()){
                    upper[word[i]]=i;
                }
            }
        }

        for(auto& el:lower){
            cout<<el.first<<"-->"<<el.second<<endl;
        }
        cout<<endl;
        for(auto& el:upper){
            cout<<el.first<<"-->"<<el.second<<endl;
        }
        cout<<endl;

        int count=0;
        for(char ch='a';ch<='z';ch++){
            char upperCh=toupper(ch);

            if(lower.find(ch)!=lower.end() && upper.find(upperCh) != upper.end()){
                if(lower[ch]<upper[upperCh]){
                    count++;
                }
            }
        }

        return count;
     
    }    
     int numberOfSpecialChars2(string word) {
       unordered_set<char> lower;
       unordered_set<char> ans;

       for(auto c:word){
        if(islower(c)){
            if(ans.find(c)!=ans.end()){
                ans.erase(c);
            } else lower.insert(c);
        } else if(isupper(c)){
            if(lower.find(tolower(c))!=lower.end()){
                ans.insert(tolower(c));
            }
        }
       }

       return ans.size();
     
    }    
     int numberOfSpecialChars(string word) {
      map<char,int>mp;
        int ans = 0, n = word.size();
        for(int i=0;i<n;i++) 
        {
            char ch = word[i];
            if(islower(ch)) mp[ch] = i+1;
            else if(mp[ch] == 0) mp[ch] = i+1;
        }

        for(char i='a';i<='z';i++)
        {
            int x = mp[i], y = mp[i - 'a' + 'A'];
            if(x and y and x < y) ans++;
        }
        return ans;
     
    }    
};


int main(){
  string str="AbBCab";
   Solution solution; 
   int ans= solution.numberOfSpecialChars(str);

   cout<<ans;
    return 0;
}
