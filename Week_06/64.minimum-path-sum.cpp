/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        if(M==0) return 0;
        int N = grid[0].size();
        for(int j=N-2; j>=0; --j) {
            grid[M-1][j] = grid[M-1][j] + grid[M-1][j+1];
        }
        for(int i=M-2; i>=0; --i) {
            grid[i][N-1] = grid[i][N-1] + grid[i+1][N-1];
        }
        for(int i=M-2; i>=0; --i) {
            for(int j=N-2; j>=0; --j) {
                grid[i][j] = grid[i][j] + min( grid[i][j+1], grid[i+1][j] );
            }
        }
        return grid[0][0];
    }
};
// @lc code=end

