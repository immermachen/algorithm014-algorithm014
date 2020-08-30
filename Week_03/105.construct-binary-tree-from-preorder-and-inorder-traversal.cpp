/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    unordered_map<int, int> inmap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;                
        for(int i=0;i<inorder.size();++i) inmap[inorder[i]] = i;
        return preorderDFS(preorder, 0, preorder.size()-1, 0, inorder.size()-1);        
    }
    TreeNode* preorderDFS(vector<int>& preorder, int preL, int preR, int inL, int inR) {        
        if(preL>preR) return nullptr;
        TreeNode* root = new TreeNode(preorder[preL]);
        int p = inmap[preorder[preL]];
        root->left = preorderDFS(preorder, preL+1, preL+p-inL, inL, p-1);
        root->right = preorderDFS(preorder, preL+p-inL+1, preR, p+1, inR);
        return root;  
    }
};
// @lc code=end

