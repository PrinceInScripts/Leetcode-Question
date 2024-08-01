

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
#include<set>
#include<regex>
#include<string>
using namespace std;

class Solution {
public:   
    
    int countSeniors1(vector<string>& details) {
       int agePerson=0;
       for(auto person:details){
            string age=person.substr(11,2);
            if(stoi(age)>=60) agePerson++;
       }

       return agePerson;
      }
    int countSeniors(vector<string>& details) {
       int agePerson=0;
       for(auto person:details){
            int ageOne=person[11];
            int ageTwo=person[12];

            if(ageOne>'6' || (ageOne=='6' || ageTwo>'0')){
                agePerson++;
            }
       }

       return agePerson;
      }
    
        
};


int main(){
  vector<string> details={"7868190130M7522","5303914400F9211","9273338290F4010"};
   Solution solution; 
 int ans= solution.countSeniors(details);

  cout<<ans<<endl;
  return 0;

}
