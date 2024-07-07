

/*
# 3208. Alternating Groups II
*/
/*
There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 

Example 1:

Input: colors = [0,1,0,1,0], k = 3

Output: 3

Explanation:



Alternating groups:



Example 2:

Input: colors = [0,1,0,0,1,0,1], k = 6

Output: 2

Explanation:



Alternating groups:



Example 3:

Input: colors = [1,1,0,1], k = 4

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
      int numberOfAlternatingGroups(vector<int>& colors, int k) {
         int n=colors.size();
         for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
         }
         int currCount=1,finalCount=0;
         for(int i=1;i<colors.size();i++){
            if(colors[i]!=colors[i-1]) currCount++;
            else currCount=1;

            if(currCount>=k) finalCount++;
               
         }

         return finalCount;

      } 
      
};


int main(){
   vector<int> colors={0,1,0,1,0};
   int k=3;
   Solution solution; 
   int ans=solution.numberOfAlternatingGroups(colors,k);

    
    cout<<ans;

    return 0;
}
