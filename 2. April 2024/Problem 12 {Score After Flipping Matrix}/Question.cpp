/*
# 861. Score After Flipping Matrix
*/
/*
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

 

Example 1:


Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
Example 2:

Input: grid = [[0]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
grid[i][j] is either 0 or 1.
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
     int matrixScore(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();

            for(int i=0;i<m;i++){
               if(grid[i][0]==0){
                  for(int j=0;j<n;j++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                  }
               }
            }
        
        for(int i=0;i<n;i++){
            int count0=0;
            int count1=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==0) count0++;
                else count1++;
            }

            if(count0>count1){
            for(int k=0;k<m;k++){
               if(grid[k][i]==0) grid[k][i]=1;
                else grid[k][i]=0;
            }
        
        }
        }

        int sum=0;
        
        for(int i=0;i<m;i++){
       int x=1;
            for(int j=n-1;j>=0;j--){
                sum+=grid[i][j]*x;
                x*=2;
            }
        }

        

        return sum;
        
    }
};


int main(){
    vector<vector<int>> nums = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    
    Solution solution; 
    int score=solution.matrixScore(nums);

    
    cout<<score << endl;

    return 0;
}
