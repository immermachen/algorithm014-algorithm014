/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
static bool compare (vector<int>& i,vector<int>& j) { return i[0]<j[0]; }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {       
        if(intervals.size()<2) return intervals;
        vector<vector<int>> res;
        
        //sort(intervals.begin(), intervals.end());//it works but slowly
        sort(intervals.begin(), intervals.end(), compare);        
        
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); ++i) {
            if(intervals[i][0]>res[res.size()-1][1]) {
                res.push_back(intervals[i]);
            } else {
                res[res.size()-1][1] = max(res[res.size()-1][1], intervals[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end

