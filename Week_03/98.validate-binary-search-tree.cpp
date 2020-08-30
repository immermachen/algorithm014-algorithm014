/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        long long maxval = LONG_MIN;
        return inorderDFS(root, maxval);
    }
    bool inorderDFS(TreeNode* root, long long& maxval) {
        if(root==nullptr) return true;
        bool left = inorderDFS(root->left, maxval);
        if(root->val > maxval) maxval = root->val;
        else return false;
        bool right = inorderDFS(root->right, maxval);
        return left & right;
    }
};
// @lc code=end

