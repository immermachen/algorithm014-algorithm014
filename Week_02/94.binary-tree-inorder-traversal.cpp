/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        helper(root, ret);
        return ret;        
    }
    void helper(TreeNode* root, vector<int>& ret) {
        if(root==nullptr) return;
        if(root->left!=nullptr) helper(root->left, ret);
        ret.push_back(root->val);
        if(root->right!=nullptr) helper(root->right, ret);
    }
};
// @lc code=end

