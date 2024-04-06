/*
# 59.Spiral matrix 2
*/
/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    
    int m=n;
    
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    int minR=0;
    int minC=0;
    int maxR=m-1;
    int maxC=n-1;

    int tne=m*n;
    int count=0;
    int a=1;

    while(minR<=maxR || minC<=maxC){
        
        for(int i=minC;i<=maxC && count<tne;i++){
            matrix[minR][i]=a;
            a++;
            count++;
        }
        minR++;

        for(int i=minR;i<=maxR && count<tne;i++){
             matrix[i][maxC]=a;
             a++;
            count++;
        }
        maxC--;

        for(int i=maxC;i>=minC && count<tne;i--){
             matrix[maxR][i]=a;
             a++;
           count++;
        }
        maxR--;

        for(int i=maxR;i>=minR && count<tne;i--){
            matrix[i][minC]=a;
            a++;
          count++;
        }
        minC++;

    }

    return matrix;
    }


};


int main(){
     int num = 4;
    
    Solution solution; 
    vector<vector<int>> result = solution.generateMatrix(num);

    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
