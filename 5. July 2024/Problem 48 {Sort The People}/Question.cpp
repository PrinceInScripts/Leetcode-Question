

/*
# 2418. Sort The People
*/
/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
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
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
      vector<string> ans;
      unordered_map<int,string> map;
      for(int i=0;i<names.size();i++){
             map[heights[i]]=names[i];
      }

      sort(heights.begin(),heights.end(),greater<int>());
      
      for(auto el:heights){
        ans.push_back(map[el]);
      }
      return ans;
      
    }    
};


int main(){
   vector<string> names={"Mary","John","Emma"};
   vector<int> heights={180,165,170};
   Solution solution; 
   vector<string> ans= solution.sortPeople(names,heights);

   for(auto el:ans){
    cout<<el<<" ";
   }
    return 0;
}
