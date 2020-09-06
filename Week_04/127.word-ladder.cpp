/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladder=1;
        unordered_set<string> words(wordList.begin(), wordList.end());        
        queue<string> q; q.push(beginWord);
        while(!q.empty()) {
            ladder++; int n=q.size();
            for(int i=0;i<n;++i) {
                string word = q.front(); q.pop();
                for(int j=0;j<word.size();++j) {
                    char c = word[j];
                    for(char l='a'; l<='z'; ++l) {
                        word[j] = l;
                        if(words.find(word)!=words.end()) {
                            if(word==endWord) return ladder;
                            q.push(word);
                            words.erase(word);
                        }                        
                    }
                    word[j] = c;
                }
            }
        }        
        return 0;
    }
};
// @lc code=end

