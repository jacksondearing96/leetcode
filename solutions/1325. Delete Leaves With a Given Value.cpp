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
    
    TreeNode* removeLeafNodes(TreeNode* node, int target) {
        if (node == nullptr) return nullptr;
        
        TreeNode* left = removeLeafNodes(node->left, target);
        TreeNode* right = removeLeafNodes(node->right, target);
        
        if (left == nullptr) node->left = nullptr;
        if (right == nullptr) node->right = nullptr;
        
        if (left == nullptr && right == nullptr && node->val == target) {
            //delete node;
            return nullptr;
        }
        
        return node;
    }
};
