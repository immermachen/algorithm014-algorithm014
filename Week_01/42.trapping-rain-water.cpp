/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    //Idea: https://leetcode.com/problems/trapping-rain-water/discuss/17391/Share-my-short-solution.
    int trap(vector<int>& height) {
        int water=0;
        int l=0, r=height.size()-1, lmax=0, rmax=0;
        while(l<r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax) {
                water += lmax-height[l++];
            } else {
                water += rmax-height[r--];                
            }
        }
        return water;
    }
    
    // //Idea: https://leetcode.com/problems/trapping-rain-water/discuss/17364/7-lines-C-C%2B%2B
    // int trap(vector<int>& height) {
    //     int water=0, r=height.size()-1, l=0, level=0;
    //     while(l<r) {
    //         int lower = height[height[l]<height[r] ? l++ : r--];
    //         level = max(level, lower);
    //         water += level - lower;
    //     }
    //     return water;
    // }
    
    // //Idea: https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c%2B%2B-code%3A-O(n)-time-O(1)-space
    // int trap(vector<int>& height) {
    //     int left=0; int right=height.size()-1;
    //     int res=0;
    //     int maxleft=0, maxright=0;
    //     while(left<=right){
    //         if(height[left]<=height[right]){
    //             if(height[left]>=maxleft) maxleft=height[left];
    //             else res+=maxleft-height[left];
    //             left++;
    //         }
    //         else{
    //             if(height[right]>=maxright) maxright= height[right];
    //             else res+=maxright-height[right];
    //             right--;
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end

