/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, 0, "", res);
        return res;
    }
    void helper(int n, int left, int right, string s, vector<string>& res) {
        if(left==n && right==n) { res.push_back(s); return; }
        if(left<n) helper(n, left+1, right, s+"(", res);
        if(left>right) helper(n, left, right+1, s+")", res);        
    }
};
// @lc code=end

