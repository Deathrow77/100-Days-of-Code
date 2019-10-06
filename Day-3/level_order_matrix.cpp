// Link - https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/

// Runtime: 4 ms, faster than 93.37% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 14.1 MB, less than 46.48% of C++ online submissions for Binary Tree Level Order Traversal.

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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        else
        {
            int lh = height(root->left);
            int rh = height(root->right);
            if(lh>rh)
                return lh+1;
            else
                return rh+1;
        }
    }
    
    void printLevel(TreeNode* root, vector<int> &res, int level)
    {
        if(root==NULL)
            return;
        else if(level==1)
            res.push_back(root->val);
        else{
            printLevel(root->left, res, level-1);
            printLevel(root->right, res, level-1);
        }
    }
    vector<vector<int>> printLevelOrder(TreeNode* root)
    {
        vector<int> res;
        vector<vector<int>> ans;
        for(int i=1;i<=height(root);i++)
        {
            printLevel(root, res, i);
            ans.push_back(res);
            res.clear();
        }
        return ans;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        return printLevelOrder(root);
    }
};