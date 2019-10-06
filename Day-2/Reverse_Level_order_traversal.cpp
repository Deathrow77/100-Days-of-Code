// Link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/submissions/
// Runtime: 8 ms, faster than 66.67% of C++ online submissions for Binary Tree Level Order Traversal II.
// Memory Usage: 14.3 MB, less than 18.92% of C++ online submissions for Binary Tree Level Order Traversal II.


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
    
    void printLevel(TreeNode* root, int level, vector<int> &res)
    {
        if(root==NULL)
        {
            return;
        }
        if(level==1)
            res.push_back(root->val);
        else
        {
            printLevel(root->left, level-1, res);
            printLevel(root->right, level-1, res);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans;
        vector<int> res;
        for(int i=h;i>=1;i--){
            res.clear();
            printLevel(root, i, res);
            ans.push_back(res);
        }
        return ans;
    }
};
