

/*
# 60. Permutation Sequence
*/
/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
   string helper(string original,int k,string ans){
       int n=original.length();
       if(n==1){
         ans+=original;
         return ans;
       }
       int fact=1;
       for(int i=2;i<=n-1;i++){
        fact*=i;
       }
       int idx=k/fact;
       if(k%fact==0) idx--;

       char ch=original[idx];
       string left=original.substr(0,idx);
       string right=original.substr(idx+1);

       int q=1;
       if(k%fact==0) q=fact;
       else q=k%fact;
       return helper(left+right,q,ans+ch);

   }
   
    string getPermutation(int n, int k) {
        string str;
        for(int i=1;i<=n;i++){
            str+=to_string(i);
        }
        return helper(str,k,"");
    }
   

};

int main()
{
    int n=4;
    int k=9;

    Solution solution;
    string ans = solution.getPermutation(n,k);
    cout<<ans;

    return 0;
    
}
