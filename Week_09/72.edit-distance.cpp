/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int>> dp(2, vector<int>(N+1, 0));
        for(int j=0; j<N+1; ++j) {
            dp[0][j]=j;//first row
        }
        for(int i=1; i<M+1; ++i) {
            int r1 = i%2, r2=(r1+1)%2;//2 row index for dp.
            char c1 = word1[i-1];
            for(int j=0; j<N+1; ++j) {
                if(j==0) {
                    dp[r1][0]=i; //first column in table
                } else {
                    char c2 = word2[j-1];
                    if(c1==c2) {
                        dp[r1][j] = dp[r2][j-1];
                    } else {
                        dp[r1][j] = 1 + min( dp[r1][j-1], min(dp[r2][j-1], dp[r2][j]));
                    }
                }
            }
        }
        return dp[M%2][N];        
    }
};
// @lc code=end

