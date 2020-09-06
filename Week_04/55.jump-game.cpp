/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    //Method1: from end to front
    bool canJump(vector<int>& nums) {  
        if(nums.size()<2) return true;
        bool res = false;
        int needStep = 0;
        for(int i=nums.size()-2;i>=0;--i) {
            if( nums[i] <= needStep ) {
                res = false;
                needStep++;
            } else {
                res = true;
                needStep=0;
            }
        }
        return res;
    }
    // //Method2: from front to end
    ////https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/
    // bool canJump(vector<int>& nums) {        
    //     int k = 0;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (i > k) return false;
    //         k = max(k, i + nums[i]);
    //     }
    //     return true;
    // }
};
// @lc code=end

