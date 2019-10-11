// Runtime: 16 ms, faster than 80.09% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 16.5 MB, less than 95.24% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.


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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int a, int b, int& c)
{
    if (c >= preorder.size()) return NULL;
    
    for (; a < b; a++) 
        if (preorder[c] == inorder[a]) break;
    
    if (a >= b) return NULL;
    
    TreeNode* root = new TreeNode(preorder[c++]);      
    root->left = helper(preorder, inorder, 0, a, c);  
    root->right = helper(preorder, inorder, a + 1, b, c);
    
    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)     {
        int Number = 0;
        return helper(preorder, inorder, 0, inorder.size(), Number);
    }
};