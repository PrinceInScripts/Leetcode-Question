/*
# 48.Rotate Image
*/
/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void swap(int* a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;

        return;
    }
    void rotate(vector<vector<int>>& matrix) {           
          int n=matrix.size();
          for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              swap(&matrix[i][j],&matrix[j][i]);
            }
          }

           for(int k=0;k<n;k++){
            // reverse(matrix[0].begin(),matrix[0].end());
            int i=0;
            int j=n-1;
            while(i<=j){
            swap(&matrix[k][i],&matrix[k][j]);
            i++;
            j--;
            }
          }

          return;
    }
};


int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    Solution solution; 
    solution.rotate(matrix);

   for (const auto& vec : matrix) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
