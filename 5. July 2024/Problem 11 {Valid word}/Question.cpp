

/*
# 3136. Valid word
*/
/*
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
 

Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.

 

Constraints:

1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.
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
   

       bool isValid(string word) {
         int size=word.size();
            if(size<3) return false;
            int vow=0,cons=0;
            bool digit=false,charlow=false,charup=false;
            for(int i=0;i<size;i++){
                if(word[i]>=48 && word[i]<=57){
                    digit=true;
                } else if (word[i]==36 || word[i]==36 || word[i]==64){
                  return false;
                } else if(word[i]>=65 && word[i]<=90){
                    charlow=true;
                     if(word[i]=='A' || word[i]=='E' || word[i]=='O' || word[i]=='I' || word[i]=='U') vow++;
                    else cons++;
                } else if(word[i]>=97 && word[i]<=122){
                    charup=true;
                    if(word[i]=='a' || word[i]=='e' || word[i]=='o' || word[i]=='i' || word[i]=='u') vow++;
                    else cons++;
                }
                else {
                    return false;
                }
            }
            bool num=(digit || charlow || charup);
            if(vow>=1 && cons>=1 && num) return true;
            else return false;
    }

      
     
    
   
};


int main(){
  string s="Ya$";
 
    Solution solution; 
   bool ans=solution.isValid(s);

    
    cout<<ans;

    return 0;
}
