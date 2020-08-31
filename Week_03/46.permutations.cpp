/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;        
        helper(nums, res, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<vector<int>>& res, int start) {
        if(nums.size()==start) {
            res.push_back(nums);
            return;
        }
        for(int i=start; i<nums.size(); ++i) {            
            swap(nums[i], nums[start]);
            helper(nums, res, start+1);
            swap(nums[i], nums[start]);
        }
    }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> perm;
    //     helper(nums, res, perm);
    //     return res;
    // }
    // void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm) {
    //     if(nums.size()==perm.size()) {
    //         res.push_back(perm);
    //         return;
    //     }
    //     for(int i=perm.size(); i<nums.size(); ++i) {
    //         perm.push_back(nums[i]);
    //         swap(nums[i], nums[perm.size()-1]);
    //         helper(nums, res, perm);            
    //         swap(nums[i], nums[perm.size()-1]);
    //         perm.pop_back();
    //     }
    // }

    // void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm) {
    //     if(nums.size()==0) {
    //         res.push_back(perm);
    //         return;
    //     }
    //     for(int i=0; i<nums.size();++i) {
    //         perm.push_back(nums[i]);
    //         //TODO: need to be improved
    //         vector<int> tmp(nums.begin(), nums.end()); tmp.erase(tmp.begin()+i);            
    //         helper(tmp, res, perm);
    //         perm.pop_back();
    //     }
    // }
};
// @lc code=end

