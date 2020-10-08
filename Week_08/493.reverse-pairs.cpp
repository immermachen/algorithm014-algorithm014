/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        //return mergeSort(nums, 0, nums.size()-1);
        return mergeSort2(nums, 0, nums.size()-1);
    }
    //Method1: using stl sort, slowly!
    int mergeSort(vector<int>& nums, int L, int R) {
        if(L>=R) return 0;
        int mid = (L+R)>>1;
        
        int res = mergeSort(nums, L, mid) + mergeSort(nums, mid+1, R);        
        for (int i=L, j=mid+1; i<=mid; ++i) {
            while(j<=R && nums[i]/2.0>nums[j]) {
                j++;
            }
            res+=j-(mid+1);
        }
        sort(nums.begin()+L, nums.begin()+R+1);//NOTE: NlogN, slowly!
        
        return res;
    }
    //Method2: 
    int mergeSort2(vector<int>& nums, int L, int R) {
        if(L>=R) return 0;
        int mid = (L+R)>>1;
        
        int res = mergeSort2(nums, L, mid) + mergeSort2(nums, mid+1, R); 
        res += merge(nums, L, mid, R);
        
        return res;
    }
    //merge + count
    int merge(vector<int>& nums, int L, int mid, int R) {
        vector<int> tmp(R-L+1, 0);        
        int res=0, i=L, j=mid+1, t=0;  
        
        //here to count between left and right sides.
        for(i=L, j=mid+1; i<=mid; ++i) {
            while(j<=R && nums[i]/2.0>nums[j]) j++;
            res += j-(mid+1);
        }
        
        for(i=L, j=mid+1; i<=mid && j<=R;) tmp[t++] = nums[i]<nums[j] ? nums[i++] : nums[j++]; 
        while(i<=mid) tmp[t++] = nums[i++];
        while(j<=R) tmp[t++] = nums[j++];
        for(i=L, t=0; i<=R;) nums[i++] = tmp[t++];
        return res;
    }
};
// @lc code=end

