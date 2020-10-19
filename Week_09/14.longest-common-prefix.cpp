/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        if (strs.size()==1) return strs[0];
        int j=0;
        for (int i=0; i<strs.size()-1; ++i) {
            if ( strs[i].size()>j && strs[i+1].size()>j &&  strs[i][j]==strs[i+1][j] ) {
                if (i==strs.size()-2 ) { i=-1; j++; }
            } else {
                break;
            }
        }        
        return j>0 ? strs[0].substr(0, j) : "";        
    }
};
// @lc code=end

