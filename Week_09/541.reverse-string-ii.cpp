/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int N = s.size();
        for (int i=0;i<N; i+=2*k) {
            //reverse(s.begin()+i, s.begin()+min(N, i+k));//use STL
            reverseString(s, i, min(N-1, i+k-1));
        }
        return s;
    }    
    void reverseString(string& s, int L, int R) {        
        while (L<R) {
            swap(s[L], s[R]);
            L++; R--;
        }
    }
};
// @lc code=end

