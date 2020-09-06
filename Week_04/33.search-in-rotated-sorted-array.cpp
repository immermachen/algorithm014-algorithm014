/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size()-1);
    }
    int helper(vector<int>& nums, int& target, int l, int r) {
        if(l>r) return -1;
        int mid = (l+r)>>1;
        if(target==nums[mid]) return mid;
        if(r==mid) return -1;
        if(l==mid) return helper(nums, target, mid+1, r);        
        
        if(nums[l] < nums[mid]) {//left is sorted
            if(target<nums[mid] && target>=nums[l]) 
                return helper(nums, target, l, mid-1);
            else 
                return helper(nums, target, mid+1, r);
        } else {// right is sorted
            if(target<=nums[r] && target>nums[mid])
                return helper(nums, target, mid+1, r);
            else 
                return helper(nums, target, l, mid-1);
        }
    }
};
// @lc code=end

