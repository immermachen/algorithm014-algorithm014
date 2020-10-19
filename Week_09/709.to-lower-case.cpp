/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string str) {
        string res=str;
        for (int i=0; i<res.size(); ++i) {
            if ( res[i]>='A' && res[i]<='Z' ) res[i]='a'+ (res[i]-'A');
        }
        return res;        
    }
};
// @lc code=end

