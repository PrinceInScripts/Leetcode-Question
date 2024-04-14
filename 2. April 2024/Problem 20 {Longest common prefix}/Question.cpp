/*
# 14. Longest common prefix
*/
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
     string longestCommonPrefix(vector<string>& strs) {
            int n=strs.size();
            if(n==1) return strs[0];

            sort(strs.begin(),strs.end());
            string first=strs[0];
            string last=strs[n-1];
            string ans="";
            for(int i=0;i<(min(first.length(),last.length()));i++){
               if(first[i]==last[i]) ans+=first[i];
               else return ans;
            }

            return ans;
    }
};

int main(){
    vector<string> strs={"flower","flow","flight"};

    Solution solution; 
    string score=solution.longestCommonPrefix(strs);

    
    cout<<score << endl;

    return 0;
}
