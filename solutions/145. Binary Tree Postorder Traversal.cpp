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
    
    void postorderTraversal(TreeNode* node, vector<int>& node_values) {
        if (node == nullptr) return;
        
        postorderTraversal(node->left, node_values);
        postorderTraversal(node->right, node_values);
        node_values.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> node_values;
        postorderTraversal(root, node_values);
        return node_values;
    }
};
