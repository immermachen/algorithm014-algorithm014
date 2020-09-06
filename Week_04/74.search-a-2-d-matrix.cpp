/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        
        int row = findRow(matrix, target);
        if(row==-1) return false;
        
        int l=0, r=matrix[row].size()-1;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]>target ) r=mid-1;
            else l = mid+1;
        }
        return false;
    }
    int findRow(vector<vector<int>>& matrix, int& target) {
        int l=0, r=matrix.size()-1;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(matrix[mid][0]<=target 
               && matrix[mid][matrix[mid].size()-1]>=target ) 
                return mid;
            if(matrix[mid][0]>target ) r=mid-1;
            else l = mid+1;
        }
        return -1;
    }
};
// @lc code=end

