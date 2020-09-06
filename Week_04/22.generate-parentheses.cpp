/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        //dfs(n, 0, 0, "", res);
        res = bfs(n);
        return res;
    }
    //Method1: DFS
    void dfs(int n, int left, int right, string s, vector<string>& res) {
        if(left==n && right==n) { res.push_back(s); return; }
        if(left<n) dfs(n, left+1, right, s+"(", res);
        if(left>right) dfs(n, left, right+1, s+")", res);        
    }
    //Method: BFS, slowly
    vector<string> bfs(int n) {
        vector<string> res;
        if(n==0) return res;
        queue<Node> q;
        Node node("(", n-1, n);
        q.push(node);
        while(!q.empty()) {
            Node curNode = q.front();
            q.pop();
            
            if(curNode.left==0 && curNode.right==0) 
                res.push_back(curNode.val);
            
            if(curNode.left>0) {
                Node next(curNode.val+"(", curNode.left-1, curNode.right ); 
                q.push(next);
            }
            if(curNode.left < curNode.right && curNode.right>0) {
                Node next(curNode.val+")", curNode.left, curNode.right-1 ); 
                q.push(next);
            }
        }
        return res;
    }
    struct Node{
        string val;
        int left;
        int right;
        Node(string v, int l, int r): val(v), left(l), right(r){}
    };
};
// @lc code=end

