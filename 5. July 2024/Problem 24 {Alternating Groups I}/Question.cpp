

/*
# 3206. Alternating Groups I
*/
/*
There is a circle of red and blue tiles. You are given an array of integers colors. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
Every 3 contiguous tiles in the circle with alternating colors (the middle tile has a different color from its left and right tiles) is called an alternating group.

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 

Example 1:

Input: colors = [1,1,1]

Output: 0

Explanation:

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
      int numberOfAlternatingGroups1(vector<int>& colors) {
         int n=colors.size();
         for(int i=0;i<n;i++){
            colors.push_back(colors[i]);
         }
         int count=0;
         for(int i=0;i<n;i++){
            if(colors[i]==colors[i+2] && colors[i]!=colors[i+1]){
                count++;
            }
         }
         return count;

      } 
      int numberOfAlternatingGroups(vector<int>& colors) {
         int n=colors.size();
         int count=0;

         for(int i=0;i<n-2;i++)
            if(colors[i]==colors[i+2] && colors[i]!=colors[i+1]) count++;
         
        if(colors[0]==colors[n-2] && colors[0]!=colors[n-1]) count++;

        if(colors[1]==colors[n-1] && colors[1]!=colors[0]) count++;
        
         return count;

      } 
};


int main(){
   vector<int> colors={0,1,0,0,1};
  
   Solution solution; 
   int ans=solution.numberOfAlternatingGroups(colors);

    
    cout<<ans;

    return 0;
}
