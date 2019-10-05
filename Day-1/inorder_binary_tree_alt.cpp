// Problems Link - https://leetcode.com/problems/binary-tree-inorder-traversal/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9 MB, less than 98.00% of C++ online submissions for Binary Tree Inorder Traversal.

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
        if(root==NULL)
            return vector<int>({});
        TreeNode* curr = root;
        TreeNode* pre = NULL;
        vector<int> res;
        while(curr!=NULL){
            if(curr->left==NULL)
            {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                pre = curr->left;
                while(pre->right!=NULL && pre->right!=curr)
                {
                    pre=pre->right;
                }
                if(pre->right==NULL)
                {
                    pre->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pre->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};