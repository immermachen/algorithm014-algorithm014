/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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
    vector<int> postorder(Node* root) {
        vector<int> res;        
        //helper(root, res);
        Iterative(root, res);
        //Iterative2(root, res);
        return res;
    }
    //Method 1: Recursive
    void helper(Node* root, vector<int>& res) {
        if(root==nullptr) return;
        for(Node* n : root->children)
            helper(n, res);
        res.push_back(root->val);
    }
    //Method 2: Iterative: just firstly use preoder iterative, then reverse the result.
    void Iterative(Node* root, vector<int>& res) {
        if(root==nullptr) return;
        stack<Node*> stackTree;
        stackTree.push(root);        
        while(!stackTree.empty()) {
            Node* tmp = stackTree.top();
            stackTree.pop();
            res.push_back(tmp->val);            
            for(Node* n : tmp->children) {
                stackTree.push(n);
            }
        }
        reverse(res.begin(), res.end());
    }
    //Method 3: Iterative:  list.push_front
    void Iterative2(Node* root, vector<int>& res) {
        if(root==nullptr) return;
        list<int> list;
        stack<Node*> stackTree;
        stackTree.push(root);        
        while(!stackTree.empty()) {
            Node* tmp = stackTree.top();
            stackTree.pop();
            list.push_front(tmp->val);            
            for(Node* n : tmp->children) {
                stackTree.push(n);
            }
        }
        vector<int> v{list.begin(), list.end()};
        res = v;
    }
};
// @lc code=end

