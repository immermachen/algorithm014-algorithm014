/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M') { board[click[0]][click[1]]='X'; return board; }   
        dfs(board, click[0], click[1]);
        return board;
    }
    void dfs(vector<vector<char>>& board, int row, int col) {
        int rows = board.size(), cols = board[0].size();
        if(!isvalid(row, col, rows, cols)) return;
        if(board[row][col]!='E') return;         
        char nums = 0;
        int i=row, j=col;
        if(isvalid(i-1, j, rows, cols) && board[i-1][j]=='M') nums++;
        if(isvalid(i+1, j, rows, cols) && board[i+1][j]=='M') nums++;
        if(isvalid(i, j-1, rows, cols) && board[i][j-1]=='M') nums++;
        if(isvalid(i, j+1, rows, cols) && board[i][j+1]=='M') nums++;
        if(isvalid(i-1, j-1, rows, cols) && board[i-1][j-1]=='M') nums++;
        if(isvalid(i-1, j+1, rows, cols) && board[i-1][j+1]=='M') nums++;
        if(isvalid(i+1, j-1, rows, cols) && board[i+1][j-1]=='M') nums++;
        if(isvalid(i+1, j+1, rows, cols) && board[i+1][j+1]=='M') nums++;    
        
        if(nums==0) board[row][col]='B';
        else {board[row][col]=(char)(nums + '0'); return;}
        
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
        dfs(board, row-1, col-1);
        dfs(board, row-1, col+1);
        dfs(board, row+1, col-1);
        dfs(board, row+1, col+1);
    }
    bool isvalid(int i, int j, int& rows, int& cols) {
        if(i<0 || j<0 || i>=rows || j>=cols) return false;
        return true;
    }
};
// @lc code=end

