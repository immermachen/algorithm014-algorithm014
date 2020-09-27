/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res=nums[0]+nums[1]+nums[2], N=nums.size();
        for(int i=0;i<N-2;++i) {
            int L=i+1, R=N-1;
            while(L<R) {
                int tmp=nums[i]+nums[L]+nums[R];
                if(tmp==target) return target;
                if( abs(res-target) > abs(tmp-target) ) res=tmp;
                if(tmp>target) { R--;} 
                else { L++; }
            }
        }
        return res;
    }
};
// @lc code=end

