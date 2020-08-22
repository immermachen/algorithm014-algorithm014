/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    //Method 2: https://leetcode.com/problems/group-anagrams/discuss/19200/C%2B%2B-unordered_map-and-counting-sort
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string sorted = s; sort(sorted.begin(), sorted.end());
            //string sorted = strSort(s); //this improved method is slower than sort();
            mp[sorted].push_back(s);
        }
        res.reserve(mp.size());
        for(auto m : mp) {
            res.push_back(m.second);
        }        
        return res;
    }
    //improve sort. But actually slowly than STL Sort!!!
    string strSort(string& s) {
        char letters[26]={0};
        string res;
        for(char& c : s) {
            letters[c-'a']++;
        }
        for(int i=0;i<26;++i) {
            res += string(letters[i], i+'a');
        }
        return res;
    }    
    
    //Method 1: Time Limited Exceeded
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> res;
    //     while(!strs.empty()) {
    //         vector<string> cur;
    //         cur.push_back(strs[strs.size()-1]);
    //         strs.erase(strs.end());
    //         for(int j=0;j<strs.size();++j) {
    //             if(isAnagrams(cur[0], strs[j])) {
    //                 cur.push_back(strs[j]);
    //                 strs.erase(strs.begin()+j);
    //                 j--;
    //             }
    //         }
    //         if(cur.size()>0) res.push_back(cur);
    //     }
    //     return res;
    // }
    // bool isAnagrams(string A, string B) {
    //     if(A.size()!=B.size()) return false;
    //     int arr[26]={};
    //     for(int i=0;i<A.size();++i) {
    //         arr[A[i]-'a']++;
    //         arr[B[i]-'a']--;
    //     }
    //     for(int i=0;i<26;++i) {
    //         if(arr[i]) return false;
    //     }
    //     return true;
    // }
};
// @lc code=end

