/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int target = INT_MAX;
        helper(nums, target, 0, nums.size()-1);
        return target;
    }
    void helper(vector<int>& nums, int& target, int l, int r) {
        if(l>r) return;
        if(l+1==r) { target = min(target, min(nums[l], nums[r])); return; }
        
        int mid = (l+r)>>1;
        target = min(target, nums[mid]);
        if(r==mid) return;//left and right done.
        //if(l==mid) helper(nums, target, mid+1, r);//left done and go right.
        
        if(nums[l] < nums[mid]) {//left is sorted.
            helper(nums, target, mid+1, r);//go right.
            target = min(target, nums[l]);
        } else {// right is sorted
            helper(nums, target, l, mid-1);//go left.
            target = min(target, nums[mid]);
        }
    }
};
// @lc code=end

