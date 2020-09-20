/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int res=0;        
        for(int i=0; i<s.size(); ++i) {
            hasPalindromic(s, i, i, res);
            hasPalindromic(s, i, i+1, res);
        }
        return res;
    }
    void hasPalindromic(string& s, int l, int r, int& res) {        
        while(l>=0 && r<s.size() && s[l]==s[r]) {
            res++;
            l--;
            r++;
        }
    }
    
    //// DP, but slowly
    // int countSubstrings(string s) {
    //     vector<bool> dp(s.size(), false);
    //     int res = 0;
    //     for (int j = 0; j < s.size(); j++) {
    //         for (int i = 0; i <= j; i++) {
    //             if (s[i] == s[j] && (j - i < 2 || dp[i + 1])) {
    //                 dp[i] = true;
    //                 res++;
    //             } else 
    //                 dp[i] = false;
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end

