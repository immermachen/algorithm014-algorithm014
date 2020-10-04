/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    //Method2: DFS+Bitwise
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> solution(n, string(n,'.'));
        dfs(res, solution, n, 0, 0, 0, 0);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& solution, int& n, int row, int col, int pie, int na) {
        if(row>=n) { res.push_back(solution); return; }
        
        int bits = ~(col | pie | na) & ( (1<<n) - 1 ); //get all usable bits
        while(bits>0) {
            int pick = bits & -bits;//pick the lowest bit 1=usable col.
            int c = getColIndex(pick, n);
            solution[row][c] = 'Q';
            dfs(res, solution, n, row+1, col|pick, (pie|pick)<<1, (na|pick)>>1);
            solution[row][c] = '.';
            bits = bits & (bits-1);//set the lowest bit 1 to 0.
        }
    }
    int getColIndex(int pick, int n) {
        while(pick>0) {
            pick=pick>>1;
            n--;
        }
        return n;
    }
    
    //Method1: DFS
    vector<vector<string>> solveNQueens_DFS(int n) {
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

