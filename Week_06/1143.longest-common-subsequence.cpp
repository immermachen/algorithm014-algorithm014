/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) return longestCommonSubsequence(text2, text1);
        vector<vector<int>> matrix(2, vector<int>(text2.size()+1, 0) );     
        for(int i=1;i<text1.size()+1;++i) {
            for(int j=1;j<text2.size()+1;++j) {
                if(text1[i-1]==text2[j-1]) {
                    matrix[i%2][j] = matrix[(i-1)%2][j-1]+1; 
                }                    
                else
                    matrix[i%2][j]=max(matrix[i%2][j-1], matrix[(i-1)%2][j]); 
            }
        }
        return matrix[text1.size()%2][text2.size()];        
    }
};
// @lc code=end

