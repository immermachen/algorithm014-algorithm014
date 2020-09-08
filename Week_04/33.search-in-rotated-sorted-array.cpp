/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //return dfs(nums, target, 0, nums.size()-1);
        return dfs2(nums, target);
    }
    int dfs2 (std::vector<int>& nums, int target) {      
        int L=0, R=nums.size()-1;
        while(L<=R) {
            int mid = L+(R-L)/2;
            if(nums[mid]==target) return mid;
            if(L==mid&&nums[R]==target) return R;
            if(nums[L]<nums[mid]) {
                if(nums[L]<=target && target<nums[mid])
                    R=mid-1;   
                else
                    L=mid+1;
            } else {
                if (nums[R]>=target && target>nums[mid])
                    L=mid+1;
                else
                    R=mid-1;   
            }     
        }
        return -1;
    }
    int dfs(vector<int>& nums, int& target, int l, int r) {
        if(l>r) return -1;
        int mid = (l+r)>>1;
        if(target==nums[mid]) return mid;
        if(r==mid) return -1;
        if(l==mid) return dfs(nums, target, mid+1, r);        
        
        if(nums[l] < nums[mid]) {//left is sorted
            if(target<nums[mid] && target>=nums[l]) 
                return dfs(nums, target, l, mid-1);
            else 
                return dfs(nums, target, mid+1, r);
        } else {// right is sorted
            if(target<=nums[r] && target>nums[mid])
                return dfs(nums, target, mid+1, r);
            else 
                return dfs(nums, target, l, mid-1);
        }
    }
};
// @lc code=end

