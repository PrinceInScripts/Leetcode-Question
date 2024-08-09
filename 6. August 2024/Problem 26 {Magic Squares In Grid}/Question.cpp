

/*
# 840. Magic Squares In Grid
*/
/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
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
    bool validSquare(vector<vector<int>>& grid,int row,int col){
        unordered_set<int> store;
        
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(grid[i][j]<1 || grid[i][j]>9 || store.find(grid[i][j])!=store.end()){
                    return false;
                }
                store.insert(grid[i][j]);
            }
        }

        
        return true;
    }
    bool magicSquare(vector<vector<int>>& grid,int row,int col){
        
        if(!validSquare(grid,row,col)) return false;

        //for row
        int sum=grid[row][col]+grid[row][col+1]+grid[row][col+2];

        for(int i=1;i<3;i++){
            if(grid[row+i][col]+grid[row+i][col+1]+grid[row+i][col+2]!=sum) return false;
        }

        //for col
        for(int i=0;i<3;i++){
            if(grid[row][col+i]+grid[row+1][col+i]+grid[row+2][col+i]!=sum) return false;

        }

        //for diagonal
        if(grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2]!=sum) return false;
        if(grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col]!=sum) return false;

        return true;


    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
       
       for(int i=0;i<=rows-3;i++){
        for(int j=0;j<=cols-3;j++){
           if(magicSquare(grid,i,j)) count++;
        }
       }

        return count;
    }
    
    
        
};


int main(){
//   vector<vector<int>> grid={{4,3,8,4},{9,5,1,6},{2,7,6,2}};
  vector<vector<int>> grid={{5,5,5},{5,5,5},{5,5,5}};
//   vector<vector<int>> grid={{8}};
   Solution solution; 
 int ans= solution.numMagicSquaresInside(grid);

  cout<<ans<<endl;
  return 0;

}
