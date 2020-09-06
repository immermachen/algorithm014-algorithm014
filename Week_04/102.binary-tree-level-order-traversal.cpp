/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Method2: BFS + queue
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;        
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> row(n,0);
            for(int i=0; i<n; ++i) {                
                TreeNode* node = q.front();
                q.pop();
                row[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(row);
        }
        return res;
    }
    
    // //Method1: DFS, faster than BFS
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> ret;
    //     if(root==NULL)  return ret;
    //     doing(root, ret, 0);
    //     return ret;
    // }
    // //using tree preorder traversal
    // void doing(TreeNode* root, vector<vector<int>>& ret, int level){
    //     if(root==NULL) return;        
    //     if(ret.size()<=level){
    //         ret.push_back(vector<int>());
    //     }        
    //     ret[level].push_back(root->val);        
    //     level++;
    //     doing(root->left, ret, level);
    //     doing(root->right, ret, level);                
    // }
};
// @lc code=end

