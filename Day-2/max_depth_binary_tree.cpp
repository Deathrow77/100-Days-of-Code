// Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Runtime: 16 ms, faster than 21.26% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.1 MB, less than 96.70% of C++ online submissions for Maximum Depth of Binary Tree.


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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
        {
            int lh = maxDepth(root->left);
            int rh = maxDepth(root->right);
            if(lh>rh)
                return lh+1;
            else
                return rh+1;
        }
    }
};