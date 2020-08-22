/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:

    //https://leetcode-cn.com/problems/top-k-frequent-elements/solution/leetcode-di-347-hao-wen-ti-qian-k-ge-gao-pin-yuan-/
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> count;
    //     vector<int> res;
    //     vector<vector<int>> buckets(nums.size()+1);
    //     for(int& i : nums) count[i]++;
    //     for(auto& m : count) buckets[m.second].push_back(m.first);
    //     for(int i=buckets.size()-1; i>=0, res.size()<k; --i)
    //         for(int& b : buckets[i]) res.push_back(b);
    //     return res;
    // }
    
    //https://leetcode.com/problems/top-k-frequent-elements/discuss/81624/C%2B%2B-O(n-log(n-k))-unordered_map-and-priority_queue(maxheap)-solution
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> res;        
        for(int& i : nums) count[i]++;
        priority_queue<pair<int,int>> heap;
        for(auto& m : count) {            
            heap.push(make_pair(m.second, m.first)); //<frequency-value>
            if ( heap.size() > count.size()-k ) {
                res.push_back(heap.top().second);
                heap.pop();
            }
        }        
        return res;
    }
};
// @lc code=end

