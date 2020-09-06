/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=0; i<prices.size()-1;++i) {
            res += max( prices[i+1]-prices[i], 0 );;
        }
        return res;
    }
    //slowly
    // int maxProfit(vector<int>& prices) {
    //     int res=0;
    //     for(int i=0; i<prices.size()-1;++i) {
    //         if(prices[i+1]>prices[i]) res+=prices[i+1]-prices[i];
    //     }
    //     return res;
    // }
};
// @lc code=end

