/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> T(26,0);
        for(char& c: tasks) { T[c-'A']++; }
        sort(T.begin(), T.end());
        int B = T[25];//number of buckets
        int idle = (B-1) * n;
        for(int i=T.size()-2; i>=0 && T[i]>0; --i) {
            if(idle<=0) return tasks.size();            
            idle -= min(B-1, T[i]);            
        }
        return tasks.size()+idle;        
    }
};
// @lc code=end

