

/*
# 100342. Find the Minimum Area to Cover All Ones I
*/
/*
You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
Return the minimum possible area of the rectangle.
 
Example 1:
Input: grid = [[0,1,0],[1,0,1]]
Output: 6
Explanation:
 
The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
Example 2:
Input: grid = [[0,0],[1,0]]
Output: 1
Explanation:
 
The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.


*/

#include <iostream>
#include <vector> 
#include<algorithm>
#include <limits.h>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>>& grid) {
      int minRow=INT_MAX,maxRow=INT_MIN;
      int minCol=INT_MAX,maxCol=INT_MIN;

      int n=grid.size();
      int m=grid[0].size();

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                minRow=min(minRow,i);
                maxRow=max(maxRow,i);
                minCol=min(minCol,j);
                maxCol=max(maxCol,j);
            }
        }
      }

      if(minRow==INT_MAX) return 0;

      int height=maxRow-minRow+1;
      int width=maxCol-minCol+1;

      return height*width;
    }
   
    
   
};

int main()
{
vector<vector<int>> nums={{0,1,0},{1,0,1}};


    Solution solution;
    double ans = solution.minimumArea(nums);
   
    cout<<ans;
    return 0;
    
}
