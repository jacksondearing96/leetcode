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
    
    pair<bool, int> isBalanced(TreeNode* node, int depth) {
        if (node == nullptr) return pair<bool, int>(true, depth);
        
        pair<bool, int> leftBalance = isBalanced(node->left, depth + 1);
        if (!leftBalance.first) return pair<bool, int>(false, depth);
        
        pair<bool, int> rightBalance = isBalanced(node->right, depth + 1);
        if (!rightBalance.first) return pair<bool, int>(false, depth);
    
        int heightDifference = abs(leftBalance.second - rightBalance.second);
        int maxHeight = max(leftBalance.second, rightBalance.second);
        return pair<bool, int>(heightDifference < 2, maxHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        return isBalanced(root, 0).first;   
    }
};
