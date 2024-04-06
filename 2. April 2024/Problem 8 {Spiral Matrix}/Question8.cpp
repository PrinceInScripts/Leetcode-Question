/*
# 54.Spiral matrix
*/
/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
      vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    int minR=0;
    int minC=0;
    int maxR=m-1;
    int maxC=n-1;

    int tne=m*n;
    int count=0;
    vector<int> result;

    while(minR<=maxR || minC<=maxC){
        
        for(int i=minC;i<=maxC && count<tne;i++){
            result.push_back(matrix[minR][i]);
            count++;
        }
        minR++;

        for(int i=minR;i<=maxR && count<tne;i++){
             result.push_back(matrix[i][maxC]);
            count++;
        }
        maxC--;

        for(int i=maxC;i>=minC && count<tne;i--){
             result.push_back(matrix[maxR][i]);
           count++;
        }
        maxR--;

        for(int i=maxR;i>=minR && count<tne;i--){
             result.push_back(matrix[i][minC]);
          count++;
        }
        minC++;

    }

    return result;
    }


};


int main(){
     vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    Solution solution; 
    vector<int> result = solution.spiralOrder(nums);

    
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    

    return 0;
}
