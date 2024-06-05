

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
        unordered_map<char,int> map;
        vector<string> ans;

        for(int i=0;i<words.size();i++){
            string s=words[i];
            for(int j=0;j<s.size();j++){
                if(map.find(s[j]) != map.end()){
                    map[s[j]]++;
                } else {
                    map[s[j]]=1;
                }
            }
        }

        for(auto& el:map){
            while(el.second>=words.size()){
                if(el.second>=words.size()){
                ans.push_back(string(1, el.first));
                el.second=el.second/2;
            }
            }
            
        }

        return ans;
    }
   

};

int main()
{
    vector<string> words={"acabcddd","bcbdbcbd","baddbadb","cbdddcac","aacbcccd","ccccddda","cababaab","addcaccd"};
    

    Solution solution;
    vector<string> ans = solution.commonChars(words);
    for(auto el:ans){
        cout<<el<<endl;
    }

    return 0;
    
}
