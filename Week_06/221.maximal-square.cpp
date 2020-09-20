/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        int res=0, M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(N+1, 0));
        for(int i=0; i<M; ++i) {
            int r1 = i%2, r2=(r1+1)%2;
            for(int j=0; j<N; ++j) {
                if(matrix[i][j]=='1') {
                    dp[r1][j+1] = min(dp[r1][j], min(dp[r2][j+1], dp[r2][j])) + 1;
                    res = max(res, dp[r1][j+1]);
                } else {
                    dp[r1][j+1] = 0;
                }
            }
        }
        return res*res;        
    }
};
// @lc code=end

