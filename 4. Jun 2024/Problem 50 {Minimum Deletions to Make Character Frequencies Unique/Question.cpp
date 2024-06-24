

/*
# 1647. Minimum Deletions to Make Character Frequencies Unique
*/
/*
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
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
     
    int minDeletions1(string s) {
        unordered_map<char,int> map;
        vector<int> freq;

        for(int i=0;i<s.size();i++){
            if(map.find(s[i])!=map.end()){
                map[s[i]]++;
            } else {
                map[s[i]]=1;
            }
        }

        for(auto& el:map){
            freq.push_back(el.second);
        }

        sort(freq.begin(),freq.end());

        int minDelCount=0;
        for(int i=1;i<freq.size();i++){
            int j=i;
            while(j>=0 && freq[j]==freq[j-1]){
                minDelCount++;
                freq[j]--;
                swap(freq[j],freq[j-1]);
                j--;
            }
        }

        return minDelCount;
        
    }
    int minDeletions2(string s) {
        unordered_map<char,int> map;
        

        for(char c:s ){
            map[c]++;
        }

        unordered_set<int> usedFreq;
        int deletion=0;

        for(auto& el:map){
            int freq=el.second;

            while(freq>0 && !usedFreq.insert(freq).second){
                 freq--;
                 deletion++;
            }
        }

        return deletion;
        
    }
    int minDeletions(string s) {
        unordered_map<char,int> map;
        

        for(char c:s ){
            map[c]++;
        }

        vector<int> freq;
        int deletion=0;

        for(auto& el:map){
           freq.push_back(el.second);           
        }

        sort(freq.begin(), freq.end(), greater<int>());
         for (int i = 1; i < freq.size(); ++i) {
            if (freq[i] >= freq[i - 1]) {
                int newFreq = max(0, freq[i - 1] - 1);
                deletion += freq[i] - newFreq;
                freq[i] = newFreq;
            }
        }

        return deletion;
        
    }
   
};


int main(){
   string s="aaabbbcc";
 
    Solution solution; 
    int ans=solution.minDeletions(s);

    
    cout<<ans;

    return 0;
}
