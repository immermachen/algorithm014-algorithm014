/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        doing(root, ret, 0);
        return ret;            
    }
    void doing(Node* root, vector<vector<int>>& ret, int level){
        if(root==NULL) return;
        if(ret.size()<=level) {
            ret.push_back(vector<int>());            
        }
        
        ret[level].push_back(root->val);
        
        level++;        
        for(Node* node : root->children) {
            doing(node, ret, level);
        }        
    }
};
// @lc code=end

