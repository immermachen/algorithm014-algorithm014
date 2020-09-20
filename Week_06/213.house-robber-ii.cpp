/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;      
        int N = nums.size();
        if(N==1) return nums[0];
        int sub1 = rob(nums, 0, N-1);
        int sub2 = rob(nums, 1, N);
        return max(sub1, sub2);
    }
    int rob(vector<int>& nums, int L, int N) {        
        int norob=0, rob=nums[L];
        for(int i=L+1; i<N; ++i) {
            int tmp = norob;
            norob = max(norob, rob);
            rob = tmp+nums[i];
        }
        return max(norob, rob);        
    }
};
// @lc code=end

