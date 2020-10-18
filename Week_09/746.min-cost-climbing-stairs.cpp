/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==0) return 0;
        if(cost.size()==1) return cost[0];
        int pre0 = cost[0];
        int pre1 = cost[1];
        for(int i=2;i<cost.size();++i) {            
            int tmp = pre1;
            pre1 = cost[i] + min(pre0, pre1);
            pre0 = tmp;
        }
        return min(pre0, pre1);        
    }
};
// @lc code=end

