/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int level=0;
        bool found=false;
        unordered_set<string> words(wordList.begin(), wordList.end());        
        unordered_set<string> visited; //tricky, insread of erase!
        if(words.find(endWord)==words.end()) return res;        
        queue<vector<string>> q;         
        vector<string> first{beginWord}; 
        q.push(first);
        while(!q.empty() && !found) {
            level++; int n = q.size();
            
            //tricky: erase all visited nodes in hashmap from last level.
            for (string w : visited) words.erase(w); visited.clear();
            
            for(int i=0; i<n; ++i) {
                vector<string> list = q.front(); q.pop();
                string word = list.back();
                for(int j=0; j<word.size(); ++j) {
                    char c = word[j];
                    for(char l='a'; l<='z'; ++l) {
                        word[j] = l;
                        if ( words.find(word)!=words.end() ) {
                            visited.insert(word);
                            vector<string> nextlevel(list);
                            nextlevel.push_back(word);
                            if(word==endWord) {
                                found=true;
                                res.push_back(nextlevel);
                            }else {
                                q.push(nextlevel);                            
                                //words.erase(word);//Note: do not erase!
                            }
                        }
                    }
                    word[j] = c;
                }
            }
        }
        return res;
    }
};
// @lc code=end

