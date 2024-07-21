

/*
# 3120. Count the Number of Special Characters I
*/
/*
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.

 

Constraints:

1 <= word.length <= 50
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
    int numberOfSpecialChars(string word) {
      sort(word.begin(),word.end());
      vector<int> words(52,0);
      int count=0;

      for(int i=0;i<word.length();i++){
        if(word[i]>=65 && word[i]<=90){
            int num=word[i]-65;
            words[num]=1;
        } else {
            int num=word[i]-97+26;
            words[num]=1;
        }
      }

      for(int i=0;i<26;i++){
        if(words[i]==1 && words[i+26]==1){
           count++;
        }
      }
      return count;
    }    
};


int main(){
  string str="aaAbcBC";
   Solution solution; 
   int ans= solution.numberOfSpecialChars(str);

   cout<<ans;
    return 0;
}
