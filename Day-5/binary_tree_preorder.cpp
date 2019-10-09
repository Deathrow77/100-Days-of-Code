// Runtime: 4 ms, faster than 58.90% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return vector<int> ({});
        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;
        while(!s.empty())
        {
            TreeNode* top = s.top();
            s.pop();
            res.push_back(top->val);
            if(top->right)
                s.push(top->right);
            if(top->left)
                s.push(top->left);
        }
        return res;
    }
};