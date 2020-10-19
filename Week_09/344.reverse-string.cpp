/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int L=0, R=s.size()-1;
        while (L<R) {
            swap(s[L], s[R]);
            L++; R--;
        }        
    }
};
// @lc code=end

