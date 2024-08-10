

/*
# 859. Regions Cut By Slashes
*/
/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:


Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.
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
     void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
     int find(int x, vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x], parent);  
        }
        return parent[x];
    }

    int regionsBySlashes(vector<string>& grid) {
       int n = grid.size();
        int dots = n + 1;
        vector<int> parent(dots * dots);
        vector<int> rank(dots * dots, 0);
        int count = 1; 
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        
        for (int i = 0; i < dots; ++i) {
            for (int j = 0; j < dots; ++j) {
                if (i == 0 || j == 0 || i == n || j == n) {
                    int cell = i * dots + j;
                    unionSets(0, cell, parent, rank); 
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    if (find(cell1, parent) == find(cell2, parent)) {
                        count++;
                    } else {
                        unionSets(cell1, cell2, parent, rank);
                    }
                } else if (grid[i][j] == '/') {
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    if (find(cell1, parent) == find(cell2, parent)) {
                        count++;
                    } else {
                        unionSets(cell1, cell2, parent, rank);
                    }
                }
            }
        }
        
        return count;


    }
    
    
        
};


int main(){
vector<string> grid={"/\\","\\/"};
   Solution solution; 
 int ans= solution.regionsBySlashes(grid);

  cout<<ans<<endl;
  return 0;

}
