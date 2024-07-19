

/*
# 1380. Lucky Numbers in a Matrix
*/
/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.

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
    
      
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
       vector<int> lucky;

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num=matrix[i][j];
            int flag1=false,flag2=false;
            for(int p=0;p<m;p++){
                if(num>matrix[i][p]){
                    flag1=true;
                    break;
                }
            }
            for(int p=0;p<n;p++){
                if(num<matrix[p][j]){
                    flag2=true;
                    break;
                }
            }

            if(!flag1 && !flag2){
                lucky.push_back(num);
            }


        }
       }

       return lucky;
    }    
};


int main(){
   vector<vector<int>> matrix={{3,7,8},{9,11,13},{15,16,17}};
   Solution solution; 
   vector<int> ans= solution.luckyNumbers(matrix);

    for(auto el:ans){
        cout<<el<<" ";
    }
    return 0;
}
