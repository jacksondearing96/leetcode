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
    
    void preorderTraversal(TreeNode* node, vector<int>& node_values) {
        if (node == nullptr) return;
        
        node_values.push_back(node->val);
        preorderTraversal(node->left, node_values);
        preorderTraversal(node->right, node_values);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> node_values;
        preorderTraversal(root, node_values);
        return node_values;
    }
};
