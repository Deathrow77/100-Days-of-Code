// Runtime: 4 ms, faster than 86.77% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 13.3 MB, less than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.

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
    
    
    void returnLevel(TreeNode* root, int level, vector<int> &res, bool flag)
    {
        if(root==NULL)
            return;
        else if(level==1)
            res.push_back(root->val);
        else if(level>1)
        {
            if(flag)
            {
                returnLevel(root->right, level-1, res, flag);
                returnLevel(root->left, level-1, res, flag);
            }else
            {
                
                returnLevel(root->left, level-1, res, flag);
                returnLevel(root->right, level-1, res, flag);
            }
            
        }
    }
    
    
    vector<vector<int>> returnans(TreeNode* root)
    {
        int h = height(root);
        vector<vector<int>> ans;
        vector<int> res;
        bool flag = false;
        for(int i=1;i<=h;i++)
        {
            returnLevel(root, i, res, flag);
            ans.push_back(res);
            res.clear();
            flag=!flag;
        }
        return ans;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return returnans(root);
    }
};