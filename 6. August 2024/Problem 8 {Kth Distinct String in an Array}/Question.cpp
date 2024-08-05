

/*
# 2053. Kth Distinct String in an Array
*/
/*
YA distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.

 

Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
 

Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
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
    string kthDistinct(vector<string>& arr, int k) {
       unordered_map<string,int> freq;

       for(int i=0;i<arr.size();i++){
           if(freq.find(arr[i]) !=freq.end()){
                     freq[arr[i]]++;
           } else {
            freq[arr[i]]=1;
           }
       }
       vector<pair<string,int>> distinctElement;
       for(int i=0;i<arr.size();i++){
          if(freq[arr[i]]==1){
             distinctElement.push_back({arr[i],i});
          }
       }

       sort(distinctElement.begin(),distinctElement.end(),[](auto& a,auto& b){
        return a.second<b.second;
       });
       
       return (distinctElement.size()<k) ? "" : distinctElement[k-1].first;

    }
    
    
        
};


int main(){
  vector<string> arr={"d","b","c","b","c","a"};
  int k=2;
   Solution solution; 
 string ans= solution.kthDistinct(arr,k);

  cout<<ans<<endl;
  return 0;

}
