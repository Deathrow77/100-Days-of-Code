// Runtime: 4 ms, faster than 58.01% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 9.2 MB, less than 80.65% of C++ online submissions for Binary Tree Postorder Traversal


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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return vector<int> ({});
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode* top = s1.top();
            s1.pop();
            s2.push(top);
            if(top->left)
                s1.push(top->left);
            if(top->right)
                s1.push(top->right);
        }
        vector<int> res;
        while(!s2.empty()){
            TreeNode* top = s2.top();
            s2.pop();
            res.push_back(top->val);
        }
        return res;
    }
};