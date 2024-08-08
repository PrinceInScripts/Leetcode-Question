

/*
# 885.Spiral Matrix III
*/
/*
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

 

Example 1:


Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
Example 2:


Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 

Constraints:

1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    bool check(int i, int j, int rows, int cols){
         if(i<rows && j<cols && i>=0 && j>=0) return true;
         else return false;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
         vector<vector<int>> ans(rows*cols);
         int layer=max({rows-rStart,cols-cStart,cStart+1,rStart+1})+1;
         ans[0]={{rStart,cStart}};
         int i=rStart,j=cStart,k=1;
         for(int a=1;a<layer;a++){
            int steps=2*a-1;
            //Right Side
            int idxI=0,idxJ=1;
            for(int p=0;p<steps;p++){
                i+=idxI,j+=idxJ;
                if(check(i,j,rows,cols)) ans[k++]={{i,j}};
            }
            //Down Side
            idxI=1,idxJ=0;
            for(int p=0;p<steps;p++){
                 i+=idxI,j+=idxJ;
                if(check(i,j,rows,cols)) ans[k++]={{i,j}};
            }
            //left Side
            idxI=0,idxJ=-1;
            steps++;
            for(int p=0;p<steps;p++){
                 i+=idxI,j+=idxJ;
                 if(check(i,j,rows,cols)) ans[k++]={{i,j}};
            }
            //Up Side
            idxI=-1,idxJ=0;
            for(int p=0;p<steps;p++){
                 i+=idxI,j+=idxJ;
                 if(check(i,j,rows,cols)) ans[k++]={{i,j}};
            }


         }

         return ans;
    }
};
int main(){
      Solution s1;
       vector<vector<int>> ans=s1.spiralMatrixIII(5,6,1,4);

       for(auto an:ans){
        for(auto el:an){
            cout<<el<<" ";
        }
        cout<<endl;
       }
}

