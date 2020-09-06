/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j]=='1') {
                    res++;
                    helper(grid, i, j);
                }                
            }
        }
        return res;
    }
    void helper(vector<vector<char>>& grid, int row, int col) {
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()) return;
        if(grid[row][col]=='0') return;
        if(grid[row][col]=='1') grid[row][col]='0';
        helper(grid, row-1, col);
        helper(grid, row+1, col);
        helper(grid, row, col-1);
        helper(grid, row, col+1);
    }    
};
// @lc code=end

