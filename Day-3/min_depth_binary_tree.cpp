// Link -- https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/

// Runtime: 8 ms, faster than 96.11% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 20 MB, less than 59.52% of C++ online submissions for Minimum Depth of Binary Tree.


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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else if(!root->left)
            return minDepth(root->right)+1;
        else if(!root->right)
            return minDepth(root->left)+1;
        else
            return min(minDepth(root->left), minDepth(root->right))+1;
    }
};