/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int nums=0;
        unordered_set<string> banks(bank.begin(), bank.end());       
        vector<char> choices{'A', 'C', 'G', 'T'};
        queue<string> q; q.push(start);
        while(!q.empty()) {
            nums++; int n = q.size();
            for(int i=0; i<n; ++i) {
                string gene = q.front(); q.pop();                
                for(int j=0; j<gene.size(); ++j) {
                    char c = gene[j];
                    for(int m=0;m<choices.size(); ++m) {
                        gene[j] = choices[m];                        
                        if(banks.find(gene)!=banks.end()) {
                            if(gene==end) return nums;
                            q.push(gene);
                            banks.erase(gene);
                        }
                    }
                    gene[j]=c;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

