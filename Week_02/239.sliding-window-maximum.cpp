/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    //https://leetcode.com/problems/sliding-window-maximum/discuss/65956/My-C%2B%2B-O(n)-deque-based-solution-with-explanation
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> buffer;
        for(int i=0; i<nums.size(); ++i) {
            while(!buffer.empty() && nums[i] >= nums[buffer.back()]) 
                buffer.pop_back();
            buffer.push_back(i);
            if(i>=k-1)
                res.push_back(nums[buffer.front()]);
            if(buffer.front()<=i-k+1)
                buffer.pop_front();            
        }
        return res;
    }
};
// @lc code=end

