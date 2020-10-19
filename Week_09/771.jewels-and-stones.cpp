/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res=0;
        int letters[128]={0};
        for (int i=0; i<J.size(); ++i) {            
            letters[ J[i] ]++;
        }
        for (int i=0; i<S.size(); ++i) {
            if ( letters[ S[i] ] ) res++;
        }
        return res;                
    }
    //Map
    int numJewelsInStones1(string J, string S) {
        int res=0;
        unordered_map<char, char> map;
        for (int i=0; i<J.size(); ++i) {
            map[J[i]]=1;
        }
        for (int i=0; i<S.size(); ++i) {
            if (map.find(S[i])!=map.end()) res++;
        }
        return res;        
    }
};
// @lc code=end

