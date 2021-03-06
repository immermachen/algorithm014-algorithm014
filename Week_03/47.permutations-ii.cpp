/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> perm;
        helper(nums, res, perm);
        return res;
    }
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm) {
        if(nums.size()==0) {
            res.push_back(perm);
            return;
        }
        for(int i=0; i<nums.size();++i) {
            if(i>0 && nums[i-1]==nums[i]) {continue;}
            perm.push_back(nums[i]);
            //TODO: need to be improved
            vector<int> tmp(nums.begin(), nums.end()); tmp.erase(tmp.begin()+i);            
            helper(tmp, res, perm);
            perm.pop_back();
        }
    }
};
// @lc code=end

