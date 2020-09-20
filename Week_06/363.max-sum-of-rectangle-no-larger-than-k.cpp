/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int resMax=INT_MIN, rows=matrix.size(), cols=matrix[0].size();
        for(int c=0; c<cols; ++c) {//next col start index 
            vector<int> rowSum(rows,0);
            for(int j=c; j<cols; ++j) {//col
                for(int i=0; i<rows; ++i) {//row
                    rowSum[i] += matrix[i][j];
                }
                resMax = max(resMax, dpmax(rowSum, k));
                if (resMax == k) return k;
            }
        }
        return resMax;
    }
    //TODO: can be improved!
    int dpmax(vector<int>& nums, int k) {
        int max = INT_MIN;
        for (int l = 0; l < nums.size(); l++) {
            int sum = 0;
            for (int r = l; r < nums.size(); r++) {
                sum += nums[r];
                if (sum > max && sum <= k) max = sum;
            }
        }
        return max;
    }
};
// @lc code=end

