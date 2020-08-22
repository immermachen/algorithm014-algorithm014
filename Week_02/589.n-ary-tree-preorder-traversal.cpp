/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
    vector<int> preorder(Node* root) {
        vector<int> ret;
        traversal(root, ret);
        //Iterative(root, ret);
        return ret;
    }
    //Method 1: recursive
    void traversal(Node* root, vector<int>& ret) {
        if(root==nullptr) return;
        ret.push_back(root->val);
        for(Node* n : root->children) {
            traversal(n, ret);
        }
    }
    //Method 2: Iterative
    void Iterative(Node* root, vector<int>& ret) {
        if(root==nullptr) return;
        stack<Node*> stackTree;
        stackTree.push(root);
        while(!stackTree.empty()){
            Node* tmp = stackTree.top();
            ret.push_back(tmp->val);
            stackTree.pop();
            for(int i=tmp->children.size()-1; i>=0; --i) {
                stackTree.push(tmp->children[i]);
            }
        }
    }
};
// @lc code=end

