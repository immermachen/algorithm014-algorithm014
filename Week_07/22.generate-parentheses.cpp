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
        //res = bfs(n);
        res = DP(n);
        return res;
    }
    //Method3: DP: "(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】,p + q = n-1，且 p,q 均为非负整数。
    //equation: dp[i] = "(" + one in dp[j] + ")" + one in dp[i-1-j];  where j in [0,i)
    vector<string> DP(int n) {        
        vector<string> res;
        if(n==0) return res;
        vector<vector<string>> dp;
        dp.push_back(vector<string>{""}); dp.push_back(vector<string>{"()"}); 
        for(int i=2; i<=n; ++i) {
            vector<string> dpi;
            for(int j=0; j<i; ++j) {
                vector<string> listp = dp[j];
                vector<string> listq = dp[i-1-j];
                for(string p : listp) {
                    for(string q : listq) {           
                        string pq = "(" + p + ")" + q;
                        dpi.push_back(pq);                        
                    }
                }
            }
            dp.push_back(dpi);
        }
        return dp[n];
    }
    
    //Method1: DFS
    void dfs(int n, int left, int right, string s, vector<string>& res) {
        if(left==n && right==n) { res.push_back(s); return; }
        if(left<n) dfs(n, left+1, right, s+"(", res);
        if(left>right) dfs(n, left, right+1, s+")", res);        
    }
    //Method2: BFS, slowly
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

