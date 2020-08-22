/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;
        for(int i=0; i<nums.size(); ++i) {
            map[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); ++i) {
            int rest = target - nums[i];
            if(map.find(rest)!=map.end() && map[rest]!=i) {
                return vector<int>{i, map[rest]};
            }
        }
        return vector<int>();
    }
    
    // Method 1: slowly
    // vector<int> twoSum(vector<int>& nums, int target) {    
    //     for(int i=0; i<nums.size()-1; ++i) {
    //         for(int j=i+1; j<nums.size(); ++j) {                
    //             if(nums[i] + nums[j]==target) {
    //                 return vector<int>{i, j};
    //             }
    //         }
    //     }
    //     return vector<int>();
    // }
};
// @lc code=end

