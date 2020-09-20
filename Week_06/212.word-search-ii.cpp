/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
    class Trie {
        private:
            bool isEnd;
            Trie* next[26];
        public:
            Trie() {
                isEnd = false;
                memset(next, 0, sizeof(next));
            }
            
            void insert(string word) {
                Trie* node = this;
                for (char c : word) {
                    if (node->next[c-'a'] == NULL) {
                        node->next[c-'a'] = new Trie();
                    }
                    node = node->next[c-'a'];
                }
                node->isEnd = true;
            }
            
            bool search(string word) {
                Trie* node = this;
                for (char c : word) {
                    node = node->next[c - 'a'];
                    if (node == NULL) {
                        return false;
                    }
                }
                return node->isEnd;
            }
            
            bool startsWith(string prefix) {
                Trie* node = this;
                for (char c : prefix) {
                    node = node->next[c-'a'];
                    if (node == NULL) {
                        return false;
                    }
                }
                return true;
            }
        };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string& w : words) {trie.insert(w);}
        vector<string> res;
        unordered_set<string> resset;
        int M=board.size(); if(M==0) return res;
        int N=board[0].size(); if(N==0) return res;
        for(int i=0; i<M;++i) {
            for(int j=0;j<N;++j) {
                dfs(i, j, board, trie, "", resset);
            }
        }
        res.insert(res.end(), resset.begin(), resset.end());
        return res;
    }
    void dfs(int x, int y, vector<vector<char>>& board, Trie& trie, string word, unordered_set<string>& res) {
        if(x<0 || y<0 || x>=board.size()|| y>=board[0].size() || board[x][y]==' ') return;
        word += board[x][y];
        if(!trie.startsWith(word)) { return; }
        if(trie.search(word)) { res.insert(word); }
        char tmp = board[x][y];
        board[x][y] = ' ';//tricky: used for visited cell.
        dfs(x+1, y, board, trie, word, res);
        dfs(x-1, y, board, trie, word, res);
        dfs(x, y+1, board, trie, word, res);
        dfs(x, y-1, board, trie, word, res);
        board[x][y] = tmp;
    }
};
// @lc code=end

