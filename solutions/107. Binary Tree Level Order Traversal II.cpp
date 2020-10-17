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
    
    void traverse(TreeNode* node, int depth, vector<vector<int>>& output) {
        if (node == nullptr) return;
        
        ++depth;
        if (output.size() < depth) output.push_back(vector<int>());
        
        traverse(node->left, depth, output);
        output[depth - 1].push_back(node->val);
        traverse(node->right, depth, output);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> output;
        traverse(root, 0, output);
        reverse(output.begin(), output.end());
        return output;
    }
};
