/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size()<p.size()) return res;
        int M = s.size(), N = p.size();
        vector<int> pat(26,0);
        for (int i=0; i<N; ++i) pat[p[i]-'a']++; 
        for (int i=0; i<N; ++i) pat[s[i]-'a']--;
        if ( isAnagram(pat) ) res.push_back(0);        
        for (int i=1; i<M-N+1; ++i) {
            pat[s[i-1]-'a']++;
            pat[s[i+N-1]-'a']--;
            if ( isAnagram(pat) ) res.push_back(i);
        }        
        return res;
    }
    bool isAnagram(vector<int>& pat) {        
        for (int j=0; j<26; ++j)
            if (pat[j]!=0) return false;
        return true;        
    }
};
// @lc code=end

