/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int MinDepth(TreeNode* node) {
        if (node == nullptr) return INT_MAX;
        
        if (node->left == nullptr && node->right == nullptr) return 1;
        
        return 1 + min(MinDepth(node->left), MinDepth(node->right));
    }
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return MinDepth(root);
    }
};
