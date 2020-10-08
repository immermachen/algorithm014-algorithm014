/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    //refer to https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-e/
    int lengthOfLIS(vector<int>& nums) {          
        int N = nums.size();
        if (N<2) return N;
        vector<int> sub(1, nums[0]);
        for(int num : nums) {
            if ( num > sub[sub.size()-1] ) {             
                sub.push_back(num); continue;
            }

            int l=0, r=sub.size()-1;
            while (l<r) {
                int mid = l + (r - l) / 2;
                if(sub[mid]==num) {
                    l=mid; break;
                }
                else if (sub[mid]<num) l=mid + 1;
                else r = mid;
            }                
            sub[l] = num;
        }
        return sub.size();
    }
};
// @lc code=end

