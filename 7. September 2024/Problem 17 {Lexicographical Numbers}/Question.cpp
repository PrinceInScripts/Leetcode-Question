

/*
# 386. Lexicographical Numbers
*/
/*
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include <limits.h>
#include<cmath>
using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n) {
         vector<int> ans;
          int current=1;
         for(int i=1;i<=n;i++){
            ans.push_back(current);
            if(current*10<=n){
                current*=10;
            } else{
                if(current>=n){
                    current/=10;
                }
                current++;

                while(current%10==0){
                    current/=10;
                }
            }
         }

         return ans;
    }
   
   

};

int main()
{
   Solution solution;
   vector<int> ans = solution.lexicalOrder(13);
   
    for(auto el:ans){
         cout<<el<<" ";
    }
 
    return 0;
}
