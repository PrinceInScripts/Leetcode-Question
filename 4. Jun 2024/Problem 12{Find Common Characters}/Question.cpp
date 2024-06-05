

/*
# 1002. Find Common Characters
*/
/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
#include<unordered_map>
using namespace std;

class Solution
{
public:
  vector<string> commonChars(vector<string>& words) {
        vector<int> min_freq(26,INT_MAX);

        for(auto& word:words){
            vector<int> freq(26,0);
            for(auto& ch:word){
                freq[ch -'a']++;
            }

            for(int i=0;i<26;i++){
                min_freq[i]=min(min_freq[i],freq[i]);
            }
        }

        vector<string> ans;
        for(int i=0;i<26;i++){
            while(min_freq[i]>0){
               ans.push_back(string(1,i+'a'));
               min_freq[i]--;
            }
        }

       return ans;
        
        
    }
   

};

int main()
{
    vector<string> words={"bella","label","roller"};
    

    Solution solution;
    vector<string> ans = solution.commonChars(words);
    for(auto el:ans){
        cout<<el<<endl;
    }

    return 0;
    
}
