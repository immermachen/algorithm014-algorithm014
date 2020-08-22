// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem264.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    // //Method 1: Precompute all possibilities in easy order and sort them.
    // //https://leetcode.com/problems/ugly-number-ii/discuss/69373/Short-and-O(n)-Python-and-C%2B%2B
    // int nthUglyNumber(int n) {
    //     if(n==1) return 1;
    //     vector<int> ugly;
    //     long long a, b, c, m=INT_MAX;
    //     for(a=1; a<m; a*=2) {
    //         for(b=a; b<m; b*=3) {
    //             for(c=b; c<m; c*=5) {
    //                 ugly.push_back(c);
    //                 //cout << c << ",";
    //             }
    //         }
    //     }
    //     sort(ugly.begin(), ugly.end());
    //     return ugly[n-1];
    // }
    
    //Method 2: 动态规划
    //https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/
    int nthUglyNumber(int n) {        
        vector<int> ugly(n);
        ugly[0]=1;
        int p2=0, p3=0, p5=0;
        for(int i=1;i<n;++i) {
            int a = ugly[p2]*2, b = ugly[p3]*3, c = ugly[p5]*5;
            ugly[i] = min( min(a,b), c );
            if(ugly[i]==a) p2++;
            if(ugly[i]==b) p3++;
            if(ugly[i]==c) p5++;
        }
        return ugly[n-1];
    }
};
// @lc code=end

