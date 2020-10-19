/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cache(26, 0);
        for(int i=0; i<s.size(); ++i) {
            cache[s[i]-'a']+=1;
        }
        for(int i=0; i<s.size(); ++i) {
            if(cache[s[i]-'a']==1) return i;
        }
        return -1;        
    }
};
// @lc code=end

