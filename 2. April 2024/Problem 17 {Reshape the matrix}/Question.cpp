

/*
# 4. reshape the matrix
*/
/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Example 1:


Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
Example 2:


Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
 
*/


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
     
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
           int row=mat.size();
           int col=mat[0].size();
           vector<vector<int>> res(r,vector <int> (c));
           if(row*col==r*c){
                    for(int p=0;p<r;p++){
                        for(int q=0;q<c;q++){
                     for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                            res[p][q]=mat[i][j];
                        }
                    }
                }
              }
           }
        
        return res;

        
    }
};


int main(){
    vector<vector<int>> nums = {{1,2},{3,4} };
    int row=1;
    int col=4;
   
    
    Solution solution; 
    
   vector<vector<int>> reshape = solution.matrixReshape(nums,row,col); 
    
    for (const auto& row : reshape) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    

    return 0;
}
