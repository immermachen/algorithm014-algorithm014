/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {        
        vector<int> ret;
        
        //preoder(root, ret);
        Iterative(root, ret);
        
        return ret;
    }
    //Method 1
    void preoder(TreeNode* root, vector<int> &ret){
        if(root==nullptr) return;
        ret.push_back(root->val);
        preoder(root->left, ret);
        preoder(root->right, ret);
    }
    //Method 2:
    void Iterative(TreeNode* root, vector<int> &ret){
        if(root==NULL) return;
        stack<TreeNode*> stackTree;
        stackTree.push(root);
        while(!stackTree.empty()){
            TreeNode* tmp = stackTree.top();
            //root
            ret.push_back(tmp->val);
            stackTree.pop();
            //right
            if(tmp->right){
                stackTree.push(tmp->right);
            }
            //left
            if(tmp->left){
                stackTree.push(tmp->left);
            }
        }        
    }
};
// @lc code=end

