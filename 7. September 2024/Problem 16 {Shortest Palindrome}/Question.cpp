

/*
# 215.  Shortest Palindrome
*/
/*
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include <limits.h>
#include<cmath>
using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;

        while(j>=0){
            if(s[i]==s[j]){
                i++;
            }
            j--;
        }

        string remain=s.substr(i);

        if(remain.size()==0) return s;

        string rev_remain=remain;

        sort(rev_remain.begin(),rev_remain.end());

        return rev_remain+shortestPalindrome(s.substr(0,i))+remain;


    }
   
   

};

int main()
{
   string nums="abcd";
  
    

    Solution solution;
   string ans = solution.shortestPalindrome(nums);
   cout<<ans<<endl;
 
    return 0;
    
}
