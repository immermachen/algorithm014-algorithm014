/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int L=s.find_first_not_of(' ');
        if (L!=string::npos) s.erase(0, L);//erase leading space.
        int R=s.find_last_not_of(' ');
        if (R!=string::npos && R<s.size()-1) s.erase(R+1, s.size()-R-1);//erase trailing space.
                
        //erase multiple spaces in between.
        for (L=0, R=0; L<s.size() && R<s.size(); ++L) {
            if (s[L]==' ') {
                R=L;
                while ( R<s.size() && s[R]==' ')  R++;
                if (R-L>1) s.erase(L, R-L-1);
            }
        }
        
        reverse(s.begin(), s.end());        
        
        //reverse single word
        for (L=0, R=0; L<s.size() && R<s.size(); ) {
            while ( R<s.size() && s[R]!=' ') R++; 
            reverse(s.begin()+L, s.begin()+R);
            L=R+1;
            R=L;
        }
        return s;        
    }
};
// @lc code=end

