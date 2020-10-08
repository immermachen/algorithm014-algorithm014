/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    //Method 2: use Array to simulate hashmap, much faster!
    bool isAnagram(string s, string t) { 
        if (s.length() != t.length()) return false;
        int n = s.length();
        int smap[26] = {0};
        for (int i = 0; i < s.size(); i++) { 
            smap[s[i] - 'a']++;
            smap[t[i] - 'a']--;
        }        
        for (int i = 0; i < 26; i++)
            if (smap[i]) return false;
        return true;
    }
    
    //Method1: use hashmap, but slowly!
    // bool isAnagram(string s, string t) {
    //     if(s.size()!=t.size()) return false;
    //     unordered_map<char, int> smap;
    //     for(int i=0; i<s.size(); ++i) {
    //         smap[s[i]]++;
    //         smap[t[i]]--;
    //     }
    //     for(auto m : smap) {
    //         if(m.second>0) return false;
    //     }
    //     return true;
    // }
};
// @lc code=end

