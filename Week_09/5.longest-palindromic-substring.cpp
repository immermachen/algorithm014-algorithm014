/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        if (N<2) return s;
        int L=0,maxL=1;
        for (int i=0;i<N;++i) {
            int L1=i, R1=i, L2=i, R2=i+1;
            int len1 = centerSpread(s, L1, R1);
            int len2 = centerSpread(s, L2, R2);            
            int maxlen = len1 > len2 ? len1 : len2;
            if (maxlen>maxL) {
                maxL = maxlen;
                L = maxlen==len1 ? L1 : L2;
            }
        }
        return s.substr(L, maxL);
    }
    int centerSpread(string& s, int& L, int& R) {
        while (L>=0 && R<s.size() && s[L]==s[R]) {
            L--; R++;            
        }        
        L++, R--;
        return R>=L ? R-L+1 : 0;
        
    }
};
// @lc code=end

