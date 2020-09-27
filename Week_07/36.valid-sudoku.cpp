/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {        
        vector<vector<char>> blocks(3,vector<char>(9,0));
        for(int i=0; i<9; i++) {
            vector<char> rows(9,0);
            for(int j=0; j<9; ++j) {                
                if( j==0 && (i==3 || i==6) )
                    blocks.assign(3, vector<char>(9,0));
                
                if(board[i][j]=='.') continue;                
                int bij = (i/3) * 3 + j/3; //get id of 9 block.
                bij=bij%3; // use 3 block instead of 9.
                int num = board[i][j]-'0'; num--;
                
                if(blocks[bij][num]>0) return false;
                else blocks[bij][num]++;
                
                if(rows[num]>0) return false;                
                else rows[num]++;
            }
        }
        for(int i=0; i<9; i++) {
            vector<char> cols(9,0);
            for(int j=0; j<9; ++j) {                
                if(board[j][i]=='.') continue; 
                int num = board[j][i]-'0'; num--;
                if(cols[num]>0) return false;
                else cols[num]++;
            }
        }
        return true;
    }
};
// @lc code=end

