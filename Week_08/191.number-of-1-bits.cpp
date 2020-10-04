/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n>0) {
            n = n&(n-1);
            res++;
        }
        return res;        
    }
    int hammingWeight_1111(uint32_t n) {
        return bitset<32>(n).count();    
    }
};
// @lc code=end

