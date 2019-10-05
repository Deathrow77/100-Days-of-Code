// Problems Link - https://leetcode.com/problems/binary-tree-inorder-traversal/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.1 MB, less than 98.00% of C++ online submissions for Binary Tree Inorder Traversal.
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* curr = root;
        while(curr!=NULL || !s.empty())
        {
            while(curr!=NULL)
            {
                if(curr!=NULL)
                    s.push(curr);
                curr = curr->left;
            }
            TreeNode* top = s.top();
            s.pop();
            res.push_back(top->val);
            curr = top->right;
        }
        return res;
    }
};