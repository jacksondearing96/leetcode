/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool helper(TreeNode* root, int sum, int acc) {
        
        if (root == NULL)
            return false;
        
        acc += root->val;
        
        if (root->left == NULL && root->right == NULL)
        {
            if (acc == sum)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        
        return helper(root->left, sum, acc) || 
               helper(root->right, sum, acc);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, sum, 0);
    }
};
