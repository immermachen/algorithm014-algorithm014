/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long L=0, R = sqrt(c);
        while(L<=R) {
            long long tmp = L*L+R*R;
            if(tmp==c) return true;
            if(tmp>c) R--;
            else L++;
        }
        return false;
    }
};
// @lc code=end

