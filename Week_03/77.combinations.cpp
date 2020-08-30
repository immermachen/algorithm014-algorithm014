/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        helper(n, k, 1, res, comb);
        return res;
    }
    void helper(int n, int k, int start, vector<vector<int>>& res, vector<int>& comb) {
        if(k==0) {
            res.push_back(comb);
            return;
        }
        for(int i=start;i<=n-k+1;++i) {
            comb.push_back(i);
            helper(n, k-1, i+1, res, comb);
            comb.pop_back();            
        }        
    }
};
// @lc code=end

