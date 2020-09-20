/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int N) {
        if(N<2) return N;
        int f0=0, f1=1,fn=0;
        for(int i=2;i<=N;++i) {
            fn = f1+f0;
            f0=f1;
            f1=fn;
        }
        return fn;
    }
};
// @lc code=end

