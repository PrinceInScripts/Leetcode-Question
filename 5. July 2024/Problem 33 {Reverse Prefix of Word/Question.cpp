

/*
# 2000. Reverse Prefix of Word
*/
/*
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
 

Constraints:

1 <= word.length <= 250
word consists of lowercase English letters.
ch is a lowercase English letter.

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
      string reversePart(int i,int j,string str){
          while(i<=j){
            swap(str[i],str[j]);
            i++;
            j--;
          }
          return str;
      }
     
      string reversePrefix(string word, char ch) {
       int idx=-1;
       for(int i=0;i<word.size();i++){
        if(word[i]==ch){
            idx=i;
            break;
        }
       }
        cout<<idx<<endl;
        if(idx==-1) return word;
        else return reversePart(0,idx,word);

    } 
      
};


int main(){
 string words="abcdefd";
 char ch='d';
   Solution solution; 
   string ans=solution.reversePrefix(words,ch);

    
    cout<<ans;
    return 0;
}
