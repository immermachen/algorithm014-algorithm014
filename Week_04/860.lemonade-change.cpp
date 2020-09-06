/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.size()==0) return true;
        if(bills[0]!=5) return false;
        int n5=1, n10=0;
        for(int i=1; i<bills.size(); ++i) {
            if (bills[i]==20) {
                if(n5>=1 && n10>=1) { n5--; n10--; }
                else if (n5>=3) { n5-=3; }
                else return false;
            } else if (bills[i]==10) {
                if(n5>0) { n5--; n10++; }
                else return false;
            } else {
                n5++;
            }
        }
        return true;
    }
};
// @lc code=end

