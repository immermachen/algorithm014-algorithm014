/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int firstZeroInd = -1;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=0){
                if(firstZeroInd>-1){
                    nums[firstZeroInd] = nums[i];
                    nums[i] = 0;
                    firstZeroInd++;
                }
            }else if (firstZeroInd==-1)
            {
                firstZeroInd = i;
            }
        }
    }
};
// @lc code=end

