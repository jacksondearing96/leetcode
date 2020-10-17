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
    void inorderTraversal(TreeNode* node, vector<int>& node_values) {
        if (node == nullptr) return;
        
        inorderTraversal(node->left, node_values);
        node_values.push_back(node->val);
        inorderTraversal(node->right, node_values);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> node_values;
        inorderTraversal(root, node_values);
        return node_values;
    }
};
