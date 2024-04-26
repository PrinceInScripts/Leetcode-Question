/*
# 49.Group anagram
*/
/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
      
     
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n=strs.size();
       vector<vector<string>> ans;

       for(int i=0;i<n;i++){
        
        if(strs[i]!="0"){
            vector<string> str={};
        string str1=strs[i];
            str.push_back(str1);
           for(int j=i+1;j<n-1;j++){
            string str2=strs[j];
            sort(str1.begin(),str1.end());
            sort(str2.begin(),str2.end());
            if(str1==str2){
                  str.push_back(strs[j]);
                  strs[j]='0';
            }
            sort(str.begin(),str.end());
        }        
        ans.push_back(str);
        }
        
       }
       int left=0;
       int right=ans.size()-1;
       while(left<=right){
        if(ans[left].size()>ans[right].size()){
            vector<string> temp=ans[left];
            ans[left]=ans[right];
            ans[right]=temp;
        }
        left++;
        right--;
       }
       return ans;
    }
};


int main(){
    vector<string> nums = {"eat","tea","tan","ate","nat","bat"};
    
    Solution solution; 
    vector<vector<string>> result = solution.groupAnagrams(nums);

    for (const auto& vec : result) {
        for (string num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
