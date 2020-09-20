/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size();
        if(N==0) return 0;
        int res=0;
        vector<int> dp(N,0);
        for(int i=1;i<N;++i) {
            if(s[i]==')') {
                if(s[i-1]=='(') {
                    dp[i] = (i-2>=0 ? dp[i-2] : 0) + 2;
                }
                else if (i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(' ) {
                    dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2] : 0);
                }
                res = max(res, dp[i]);
            }
        }
        return res;        
    }
};
// @lc code=end

