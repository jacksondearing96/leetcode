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
    
    void levelOrder(TreeNode* node, int level, vector<vector<int>>& rows) {
        if (node == nullptr) return;
        
        if (rows.empty() || level > rows.size() - 1) rows.push_back({});
​
        rows[level].push_back(node->val); 
        
        levelOrder(node->left, level + 1, rows);
        levelOrder(node->right, level + 1, rows);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rows = {};
        levelOrder(root, 0, rows);
        return rows;
    }
};
