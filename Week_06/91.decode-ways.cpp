/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        if(N==0 || s[0]=='0') return 0;
        int pre=1, cur=1;
        for(int i=1;i<N;++i) {
            int tmp = cur;
            if(s[i]=='0') {
                if(s[i-1]=='1' || s[i-1]=='2')
                    cur = pre; //no additional way, dp[i]=dp[i-2];
                else
                    return 0;
            } else if(s[i-1]=='1' || (s[i-1]=='2' && s[i]>='1' && s[i]<='6')) {
                //case1: s[i-1] and s[i] separately, then dp[i]=dp[i-1], here: cur=cur;
                //case2: s[i-1] and s[i] together, then dp[i]=dp[i-2], here: cur=pre;
                // so put case1 and case2 together: 
                cur = cur + pre;
            }
            pre = tmp;
        }
        return cur;    
    }
};
// @lc code=end

