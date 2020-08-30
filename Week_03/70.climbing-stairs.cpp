/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
    map<int, int> cache;
public:
    int climbStairs(int n) {
        if(n<3) return n;         
        int n2 = cache[n-2]>0 ? cache[n-2] : cache[n-2]=climbStairs(n-2);
        int n1 = cache[n-1]>0 ? cache[n-1] : cache[n-1]=climbStairs(n-1);
        return n1+n2;        
    }    
    // int climbStairs(int n) {
    //     if(n<0) return 0;
    //     if(n==0) return 1;
    //     if(cache.find(n)!=cache.end()) return cache[n];
    //     int n12 = climbStairs(n-2) + climbStairs(n-1);
    //     cache[n] = n12;
    //     return n12;
    // }
};
// @lc code=end

