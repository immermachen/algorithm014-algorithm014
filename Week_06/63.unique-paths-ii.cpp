/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();        
        vector<int> dp(n,0); dp[0]=1;
        for(int i=0; i<m; ++i) {            
            for(int j=0; j<n; ++j) {
                if(obstacleGrid[i][j]==0) {
                    //int left = j-1<0 || obstacleGrid[i][j-1]==1 ? 0 : dp[j-1];                    
                    //dp[j] = dp[j] + left;
                    dp[j] += j-1<0 ? 0 : dp[j-1];//summary of above!
                } else {
                    dp[j] = 0;
                }
            }
        }
        return dp[n-1];         
    }
};
// @lc code=end

