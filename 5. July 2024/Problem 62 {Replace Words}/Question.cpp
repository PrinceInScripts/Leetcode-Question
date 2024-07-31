

/*
# 648. Replace words
*/
/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.

 
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
    bool checkWords(string word,string str){
        int count=0;
        for(int i=0;i<word.size();i++){
                if(word[i]==str[i]){
                    count++;
                }
        }
        return count==word.size();
    } 
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n=dictionary.size();
        stringstream ss(sentence);
        string temp;
        vector<string> words;
        while(ss>>temp){
            words.push_back(temp);
        }
        for(int i=0;i<n;i++){
            string num=dictionary[i];

            for(int j=0;j<words.size();j++){
                if(words[j].size()>num.size()){
                    if(checkWords(num,words[j])){
                        words[j]=num;
                    }
                }
            }
        }
          
        string ans=""; 
        ans+=words[0];

        for(int i=1;i<words.size();i++){
               ans=ans+" "+words[i];
        }
        

        return ans;
      }
        
};


int main(){
//   vector<string> dictionary={"cat","bat","rat"};
  vector<string> dictionary={"a","b","c"};
  string sentence="aadsfasf absbs bbab cadsfafs";
//   string sentence="the cattle was rattled by the battery";
   Solution solution; 
 string ans= solution.replaceWords(dictionary,sentence);

  cout<<ans<<endl;
  return 0;

}
