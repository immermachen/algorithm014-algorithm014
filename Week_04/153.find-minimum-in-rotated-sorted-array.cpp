/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        //int target = INT_MAX;   dfs(nums, target, 0, nums.size()-1);   return target;
        return dfs2(nums);
    }
    
    //DFS without recusive
    int dfs2(vector<int>& nums) {
        //if(nums.size()==0)
        int L=0, R=nums.size()-1;
        if(nums[L]<nums[R]) return nums[0];
        while(L<R) {
            if(L+1==R) return nums[R];
            int mid = L+(R-L)/2;
            if(nums[L]<nums[mid]) L=mid;
            else R=mid;
        }
        return nums[0];
    }
    //DFS
    void dfs(vector<int>& nums, int& target, int l, int r) {
        if(l>r) return;
        if(l+1==r) { target = min(target, min(nums[l], nums[r])); return; }
        
        int mid = (l+r)>>1;
        target = min(target, nums[mid]);
        if(r==mid) return;//left and right done.
        //if(l==mid) dfs(nums, target, mid+1, r);//left done and go right.
        
        if(nums[l] < nums[mid]) {//left is sorted.
            dfs(nums, target, mid+1, r);//go right.
            target = min(target, nums[l]);
        } else {// right is sorted
            dfs(nums, target, l, mid-1);//go left.
            target = min(target, nums[mid]);
        }
    }
};
// @lc code=end

