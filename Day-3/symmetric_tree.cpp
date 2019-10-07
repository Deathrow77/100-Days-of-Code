// Runtime: 8 ms, faster than 46.97% of C++ online submissions for Symmetric Tree.
// Memory Usage: 14.5 MB, less than 100.00% of C++ online submissions for Symmetric Tree.

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
    bool isMirror(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        if(root1 && root2 && root1->val == root2->val)
            return isMirror(root1->left, root2->right)&&isMirror(root1->right, root2->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};



// Alternative Approach using Queue

// Runtime: 8 ms, faster than 46.97% of C++ online submissions for Symmetric Tree.
// Memory Usage: 14.9 MB, less than 40.68% of C++ online submissions for Symmetric Tree.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty())
        {
            TreeNode* ln = q.front();
            q.pop();
            TreeNode* rn = q.front();
            q.pop();
            if(ln->val!=rn->val)
                return false;
            if(ln->left && rn->right)
            {
                q.push(ln->left);
                q.push(rn->right);
            }else if(ln->left || rn->right)
            {
                return false;
            }
            if(ln->right && rn->left){
                q.push(ln->right);
                q.push(rn->left);
            }else if(ln->right || rn->left)
                return false;
        }
        return true;
    }
};