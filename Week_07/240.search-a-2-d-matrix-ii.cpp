/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        int M = matrix.size(), N = matrix[0].size(), i=0, j=N-1, n=0;        
        while(i<M && j>=0) {
            n = matrix[i][j];
            if(n==target) return true;
            if(n<target) {
                i++;
            } else {
                j--;
            }
        }
        return false;        
    }
};
// @lc code=end

