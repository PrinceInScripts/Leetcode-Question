

/*
# 2220. Count the Number of Consistent Strings
*/

/*
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

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
  
   
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> ch(26,0);

        for(int i=0;i<allowed.size();i++){
            ch[allowed[i]-'a']=1;
        }
        int ans=0;
        for(auto word:words){
            int count=1;
            for(auto c:word){
                if(ch[c-'a']==0){
                    count=0;
                    break;
                }
            }
            ans+=count;
        }

        return ans;
    } 
};


int main(){
    vector<string> words={"ad","bd","aaab","baa","badab"};
    Solution solution; 
    int ans= solution.countConsistentStrings("ab",words);
    
   cout<<ans;

}
