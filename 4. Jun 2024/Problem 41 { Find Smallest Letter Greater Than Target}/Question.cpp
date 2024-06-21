

/*
# 455. Find Smallest Letter Greater Than Target
*/
/*
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
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
   char nextGreatestLetter(vector<char>& letters, char target) {
       int lo=0;
       int hi=letters.size()-1;
       char ans=letters[0];
       while(lo<=hi){
         int mid=lo+(hi-lo)/2;

         if(letters[mid]<=target) lo=mid+1;
         else{
            ans=letters[mid];
            hi=mid-1;
         }
         
       }
       return ans;
    }
};

int main()
{
  vector<char> letters = {'c','f','j'};
  char target ='c';

    Solution solution;
    char ans = solution.nextGreatestLetter(letters,target);
   
    cout<<ans;
    return 0;
    
}
