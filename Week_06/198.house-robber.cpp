/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1) return 0;
        int norob=0, rob=nums[0];
        for(int i=1; i<nums.size(); ++i) {
            int tmp = norob;
            norob = max(norob, rob);
            rob = tmp + nums[i];
        }
        return max(rob, norob);        
    }
};
// @lc code=end

