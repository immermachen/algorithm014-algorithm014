/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> solution(n, string(n,'.'));
        dfs(res, solution, 0, n);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& solution, int row, int& n) {
        if(row==n) {
            res.push_back(solution); return;
        }
        for(int j=0; j<n; ++j) {
            if(isValid(row, j, solution, n)) {
                solution[row][j] = 'Q';
                dfs(res, solution, row+1, n);
                solution[row][j] = '.';            
            }            
        }        
    }
    bool isValid(int row, int col, vector<string>& solution, int& n) {
        for(int i=0; i<row; ++i) { //check col
            if(solution[i][col]=='Q') return false;
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; --i, ++j) { //check right-upper
            if(solution[i][j]=='Q') return false;
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; --i, --j) { //check left-upper
            if(solution[i][j]=='Q') return false;
        }
        return true;        
    }
};
// @lc code=end

