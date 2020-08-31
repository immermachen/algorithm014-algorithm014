/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ret;
        encode(root, ret);
        //cout << ret.str() << endl;
        return ret.str();
    }
    void encode(TreeNode* root, ostringstream& res) {
        if(root==nullptr) { res<<"# ";   return; }
        res << root->val << ' ';
        encode(root->left, res); encode(root->right, res);
    }
    TreeNode* decode(istringstream& res) {
        string val;   res >> val;
        if(val == "#") return nullptr;
        TreeNode* root = new TreeNode( stoi(val) );
        root->left = decode(res);   root->right = decode(res);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {   
        TreeNode* ret;
        istringstream in(data);
        ret = decode(in);
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

